#include "fw_export_instance.h"

#define EXTENSION_FUNCTIONS

#include "api_error_codes.h"
#include "api_message_ids.h"
#include "fw_data_requester.h"

namespace cq
{
namespace framework
{
    ExportInstance::ExportInstance()
        : m_canceled(false)
    {
    }

    ExportInstance::~ExportInstance()
    {
        waitForDone();
    }

    void ExportInstance::handleValidate(const ValidateExport &validate_telegram, ValidateExportResponse &response)
    {
        ValidationContext context;
        context.m_properties = validate_telegram.m_properties;
        for (const auto& channel_id : validate_telegram.m_properties.m_channels)
        {
            auto new_input_channel = std::make_shared<InputChannel>(m_host, channel_id);
            new_input_channel->updateDataFormat();
            new_input_channel->updateTimeBase();
            context.m_channels.emplace(channel_id, std::move(new_input_channel));
        }

        validate(context, response);
    }

    void ExportInstance::initInstance(cq::IfHost* host)
    {
        m_host = host;
    }

    cq::IfHost* ExportInstance::getHost() const noexcept
    {
        return m_host;
    }

    void ExportInstance::handleStartExport(const cq::StartExport& start_telegram)
    {
        cq::ValidateExportResponse response;
        cq::ValidateExport validate;
        validate.m_properties = start_telegram.m_properties;
        handleValidate(validate, response);

        if (!response.m_success)
        {
            this->notifyError();
            return;
        }

        m_telegram = start_telegram;
        m_context.m_properties = start_telegram.m_properties;

        bool export_waveform = true;
        bool export_statistic = false;

        if (m_context.m_properties.m_custom_properties.containsProperty("WAVEFORM"))
        {
            export_waveform = m_context.m_properties.m_custom_properties.getBool("WAVEFORM");
        }
        if (m_context.m_properties.m_custom_properties.containsProperty("STATISTIC"))
        {
            export_statistic = m_context.m_properties.m_custom_properties.getBool("STATISTIC");
        }

        for(const auto& channel_id : start_telegram.m_properties.m_channels)
        {
            auto new_input_channel = std::make_shared<InputChannel>(m_host, channel_id);
            new_input_channel->updateDataFormat();
            new_input_channel->updateTimeBase();
            m_context.m_channels.emplace(channel_id, std::move(new_input_channel));

            auto& first_interval = start_telegram.m_properties.m_export_intervals.front();

            if (export_waveform)
            {
                auto raw_requester = std::make_unique<DataRequester>(getHost(), channel_id);
                try
                {
                    m_context.m_channel_iterators[channel_id] =
                        raw_requester->getIterator(first_interval.m_begin, first_interval.m_end);
                }
                catch (const std::exception&)
                {
                    // no valid data
                }
                m_data_requester.push_back(std::move(raw_requester));
            }

            if (export_statistic)
            {
                auto reduced_requester = std::make_unique<DataRequester>(getHost(), channel_id, true);
                try
                {
                    m_context.m_reduced_channel_iterators[channel_id] =
                        reduced_requester->getIterator(first_interval.m_begin, first_interval.m_end);
                }
                catch (const std::exception&)
                {
                    // no valid data
                }
                m_reduced_requester.push_back(std::move(reduced_requester));
            }
        }

        auto exportFunction = [this]()
        {
            bool success = true;
            try
            {
                success = this->exportData(this->m_context);
            }
            catch(const std::exception&)
            {
                this->cancel();
                success = false;
            }

            if (success)
            {
                this->notifyDone();
            }
            else
            {
                this->notifyError();
            }
        };
        m_worker_thread = std::thread(exportFunction);
    }

    void ExportInstance::setCanceled()
    {
        m_canceled.store(true, std::memory_order_release);
        waitForDone();
    }

    void ExportInstance::waitForDone()
    {
        if (m_worker_thread.joinable())
        {
            m_worker_thread.join();
        }
    }

    uint64_t ExportInstance::getID() const
    {
        return m_telegram.m_transaction_id;
    }

    void ExportInstance::notifyProgress(uint64_t progress) const
    {
        if (m_canceled.load(std::memory_order_acquire))
        {
            throw std::runtime_error("transaction cancelled");
        }

        auto p = m_host->createValue<cq::IfUIntValue>();
        p->set(progress);
        m_host->messageSync(cq::host_msg::EXPORT_PROGRESS, m_telegram.m_transaction_id, p.get(), nullptr);
    }

    void ExportInstance::notifyDone() const
    {
        m_host->messageSync(cq::host_msg::EXPORT_FINISHED, m_telegram.m_transaction_id, nullptr, nullptr);
    }

    void ExportInstance::notifyError() const
    {
        auto error_code = cq::error_codes::INTERNAL_ERROR;
        auto param = m_host->createValue<cq::IfUIntValue>();
        param->set(error_code);
        m_host->messageSync(cq::host_msg::EXPORT_FAILED, m_telegram.m_transaction_id, param.get(), nullptr);
    }
}
}