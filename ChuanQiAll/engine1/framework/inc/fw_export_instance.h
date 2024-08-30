#pragma once

#include "api_export_xml.h"
#include "base_if_host_fwd.h"
#include "fw_input_channel.h"
#include "fw_stream_iterator.h"
#include "uni_defines.h"

#include <atomic>
#include <map>
#include <memory>
#include <thread>
#include <stdint.h>

namespace cq
{
namespace framework
{
    class DataRequester;

    class ExportInstance
    {
    public:
        class ValidationContext
        {
        public:
            std::map<uint64_t, std::shared_ptr<InputChannel>> m_channels;
            cq::ExportProperties m_properties;
        };

        class ProcessingContext : public ValidationContext
        {
        public:
            std::map<uint64_t, std::shared_ptr<cq::framework::StreamIterator>> m_channel_iterators;
            std::map<uint64_t, std::shared_ptr<cq::framework::StreamIterator>> m_reduced_channel_iterators;
        };

        ExportInstance();
        virtual ~ExportInstance();

        void handleValidate(const cq::ValidateExport& validate_telegram, cq::ValidateExportResponse& response);
        void handleStartExport(const cq::StartExport& start_telegram);

        void setCanceled();

        void waitForDone();

        CQ_NODISCARD uint64_t getID() const;

        virtual void validate(const ValidationContext& context, cq::ValidateExportResponse& response) const = 0;
        virtual bool exportData(const ProcessingContext& context) = 0;
        virtual void cancel() = 0;

    private:
        template<class ExportInstance>
        friend class ExportPlugin;

        void initInstance(cq::IfHost* host);
        void notifyDone() const;
        void notifyError() const;

    protected:
        CQ_NODISCARD cq::IfHost* getHost() const noexcept;

        void notifyProgress(uint64_t progress) const;

    private:
        cq::IfHost* m_host = nullptr;
        std::thread m_worker_thread;
        std::atomic<bool> m_canceled;
        std::vector<std::unique_ptr<DataRequester>> m_data_requester;
        std::vector<std::unique_ptr<DataRequester>> m_reduced_requester;
        ProcessingContext m_context;
        cq::StartExport m_telegram;
    };
}
}
