#pragma once

#include "base_api_object_ptr.h"
#include "base_if_plugin.h"
#include "api_error_codes.h"
#include "api_message_ids.h"

#include "fw_if_message_handler.h"

#include <memory>
#include <set>
#include <string>

#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"
#endif


#ifdef WIN32
# ifdef __GNUC__
#  define DLL_EXPORT __attribute__ ((dllexport))
#  define EXTERN_C extern "C"
# else
#  ifndef EXTERN_C
#    define EXTERN_C WINAPI
#  endif
#  define DLL_EXPORT __declspec(dllexport)
# endif
#else
# define DLL_EXPORT __attribute__ ((visibility ("default")))
# define EXTERN_C extern "C"
#endif


#define CQ_REGISTER_PLUGIN(PLUGIN_NAME, PLUGIN_MANIFEST, PLUGIN_CLASS)                                                  \
            extern "C" {                                                                                                \
                DLL_EXPORT const char* cqGetPluginName() { return PLUGIN_NAME; }                                        \
                DLL_EXPORT const char* cqGetPluginManifest() { return PLUGIN_MANIFEST; }                                \
                DLL_EXPORT int cqCreatePlugin(cq::UuidType uuid, void** plugin) {                                       \
                    if (uuid == cq::ChuanQi_Plugin_Uuid) {                                                              \
                        if (plugin) {                                                                                   \
                            auto plugin_inst = new PLUGIN_CLASS();                                                      \
                            *plugin = plugin_inst;                                                                      \
                        }                                                                                               \
                        return true;                                                                                    \
                    }                                                                                                   \
                    return false;                                                                                       \
                }                                                                                                       \
                DLL_EXPORT void cqDeletePlugin(cq::UuidType uuid, void* plugin) {                                       \
                    if (uuid == cq::ChuanQi_Plugin_Uuid) {                                                              \
                        auto plugin_inst = static_cast<PLUGIN_CLASS*>(plugin);                                          \
                        delete plugin_inst;                                                                             \
                    }                                                                                                   \
                }                                                                                                       \
            }

namespace cq
{
namespace framework
{

    class PluginBase : public cq::IfPlugin
    {
    public:
        PluginBase()
            : m_host(nullptr)
            , m_registered(false)
        {
        }

        // only override for special message handling; normal stuff should register handlers
        virtual bool handleMessage(cq::PluginMessageId id, std::uint64_t key, const cq::IfValue* param, const cq::IfValue** ret, std::uint64_t& ret_code)
        {
            CQ_UNUSED(id);
            CQ_UNUSED(key);
            CQ_UNUSED(param);
            CQ_UNUSED(ret);
            CQ_UNUSED(ret_code);
            return false;
        }

        virtual std::uint64_t init(std::string& error_message) = 0;
        virtual bool deinit() = 0;

        virtual ~PluginBase() = default;

    protected:
        cq::IfHost* getHost()
        {
            return m_host;
        }

        const cq::IfHost* getHost() const
        {
            return m_host;
        }

        bool addTranslation(const char* translation_xml);
        bool addQtResources(const void* rcc, std::uint64_t rcc_size);

        void PLUGIN_API setPluginHost(cq::IfHost* host) override
        {
            m_host = host;
            for (auto& handler : m_message_handlers)
            {
                handler->setHost(host);
            }
        }

        void addMessageHandler(std::shared_ptr<IfMessageHandler> handler)
        {
            m_message_handlers.insert(handler);
            handler->setHost(getHost());
        }

    private:
        std::uint64_t PLUGIN_API pluginMessage(
            cq::PluginMessageId id, std::uint64_t key,
            const cq::IfValue* param, const cq::IfValue** ret) final;

    private:
        cq::IfHost* m_host;
        std::set<std::shared_ptr<IfMessageHandler>> m_message_handlers;
        bool m_registered;
    };


}
}
