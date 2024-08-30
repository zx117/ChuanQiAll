#pragma once

#define EXTENSION_FUNCTIONS

#include "fw_plugin_base.h"
#include "fw_export_instance.h"

#include "api_channel_list_xml.h"
#include "api_event_ids.h"
#include "api_export_xml.h"
#include "api_utils.h"
#include "uni_defines.h"

namespace cq
{
namespace framework
{

    class ExportPluginBase : public PluginBase
    {
    public:

        virtual void registerTranslations() {};
        virtual void registerResources() { registerTranslations(); }

    protected:
        std::uint64_t init(std::string& error_message) final;
        bool deinit() final;

        void registerExport();
        void unregisterExport();

        virtual cq::RegisterExport getExportInfo() = 0;

        bool checkChuanQiCompatibility();
    };

    template<class ExportInstance>
    class ExportPlugin : public ExportPluginBase
    {

    private:
        cq::RegisterExport getExportInfo() final
        {
            return ExportInstance::getExportInfo();
        }

        std::shared_ptr<ExportInstance> getTransaction(uint64_t id)
        {
            auto match = std::find_if(m_instances.begin(), m_instances.end(),
                                      [&id](std::shared_ptr<ExportInstance>& instance)
                                      {
                                          return instance->getID() == id;
                                      });

            if(match != m_instances.end())
            {
                return *match;
            }
            return nullptr;
        }

        bool handleMessage(cq::PluginMessageId id, std::uint64_t key, const cq::IfValue* param, const cq::IfValue** ret, std::uint64_t& ret_code) override
        {
            switch (id)
            {

            case cq::plugin_msg::EXPORT_VALIDATE_SETTINGS:
            {

                ValidateExport telegram;

                if (parseXMLValue(param, telegram))
                {
                    cq::ValidateExportResponse response;

                    ExportInstance instance;
                    instance.initInstance(getHost());
                    instance.handleValidate(telegram, response);

                    if (ret)
                    {
                        auto error_xml = response.generate();
                        auto result = getHost()->template createValue<cq::IfXMLValue>();
                        result->set(error_xml.c_str());
                        *ret = result.detach();
                    }
                }

                ret_code = cq::error_codes::OK;
                return true;
            }
            case cq::plugin_msg::EXPORT_GENERATE_NAME:
            {
                return true;
            }
            case cq::plugin_msg::EXPORT_START:
            {
                ret_code = cq::error_codes::INVALID_INPUT_PARAMETER;

                cq::StartExport telegram;
                if (parseXMLValue(param, telegram))
                {
                    if(getTransaction(telegram.m_transaction_id))
                    {
                        ret_code = cq::error_codes::INTERNAL_ERROR;
                        return true;
                    }

                    auto instance = std::make_shared<ExportInstance>();

                    instance->initInstance(getHost());
                    m_instances.push_back(instance);
                    instance->handleStartExport(telegram);

                    ret_code = cq::error_codes::OK;
                }
                return true;
            }
            case cq::plugin_msg::EXPORT_CANCEL:
            {
                if(auto transaction = getTransaction(key))
                {
                    transaction->setCanceled();
                    m_instances.erase(std::remove(m_instances.begin(), m_instances.end(), transaction), m_instances.end());
                }

                return true;
            }
            case cq::plugin_msg::EXPORT_FINALIZE:
            {
                if(auto transaction = getTransaction(key))
                {
                    transaction->waitForDone();
                    m_instances.erase(std::remove(m_instances.begin(), m_instances.end(), transaction), m_instances.end());
                }
                return true;
            }
            default:
                return false;
            }
        }

    private:
        std::vector<std::shared_ptr<ExportInstance>> m_instances;
    };

}
}

