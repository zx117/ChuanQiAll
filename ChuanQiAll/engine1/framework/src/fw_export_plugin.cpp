#include "fw_export_plugin.h"

#include "fw_version_check.h"

#include "api_utils.h"
#include "base_message_return_value_holder.h"

namespace cq
{
namespace framework
{
    static const char* REQUIRED_CHUANQI_VERSION = "1.0";

    void ExportPluginBase::registerExport()
    {
        const auto telegram = getExportInfo();
        auto xml_msg = getHost()->template createValue<cq::IfXMLValue>();
        xml_msg->set(telegram.generate().c_str());
        getHost()->messageSync(cq::host_msg::EXPORT_REGISTER, 0, xml_msg.get(), nullptr);
    }

    void ExportPluginBase::unregisterExport()
    {
        auto format_id = getHost()->template createValue<cq::IfStringValue>();
        const auto telegram = getExportInfo();
        format_id->set(telegram.m_format_id.c_str());
        getHost()->messageSync(cq::host_msg::EXPORT_UNREGISTER, 0, format_id.get(), nullptr);
    }

    bool ExportPluginBase::checkChuanQiCompatibility()
    {
        auto name = getHost()->getValue<cq::IfStringValue>(cq::queries::PluginHost, cq::queries::PluginHost_Name);
        auto version = getHost()->getValue<cq::IfStringValue>(cq::queries::PluginHost, cq::queries::PluginHost_VersionString);
        if (name && version)
        {
            if (std::string("ChuanQi") == name->getValue())
            {
                if (compareVersionStrings(REQUIRED_CHUANQI_VERSION, version->getValue()) <= 0)
                {
                    return true;
                }
            }
        }
        return false;
    }

    std::uint64_t ExportPluginBase::init(std::string& error_message)
    {
        if (!checkChuanQiCompatibility())
        {
            error_message = "Current version of ChuanQi is not supported.";
            return cq::error_codes::UNSUPPORTED_VERSION;
        }

        registerResources();
        registerExport();
        return cq::error_codes::OK;
    }

    bool ExportPluginBase::deinit()
    {
        unregisterExport();
        return true;
    }

}
}

