#ifndef IAPPHOST_H
#define IAPPHOST_H

#include <QObject>
#include <QVariant>
#include <QString>

#include "app.h"

class IAppHost
{
public:
    /**
         * Generic function for sending predefined messages to the host and receive a synchronous result.
         * @param  msg_id Describes the type and semantics of the message.
         *                Check piapi_message_ids.h, namespace "host_msg" for valid values and more information about each message.
         * @param  key    Meaning of this parameter depends on the message type. Can be used to select which instance (of many) the message targets.
         * @param  param  Meaning and type of this parameter depends on the message type.
         * @param  ret    Meaning and type of the value assigned to this
         *                parameter depends on the message type (OUT param only, will not be read).
         * @return        Meaning depends on the message type. Returns (uint64)-1 for unknown or not implemented messages.
         */
    virtual std::uint64_t messageSync(MessageId msg_id, std::uint64_t key, const QVariant* param, const QVariant** ret = nullptr) = 0;

    /**
         * Generic function for sending predefined messages to the host and receive a synchronous result.
         * This version avoids the overhead of creating and initializing an IfValue instance and directly reads from the supplied memory location.
         * Plese check the documentation to see which messages support this function and how the memory is interpreted.
         * @param  msg_id Describes the type and semantics of the message.
         *                Check piapi_message_ids.h, namespace "host_msg" for valid values and more information about each message.
         * @param  key    Meaning of this parameter depends on the message type. Can be used to select which instance (of many) the message targets.
         * @param  param       Pointer to a data buffer that has to remain unchanged until the call is completed.
         * @param  param_size  Size of the data buffer in bytes. If buffer contains string or xml data this has to include the 0-termination character.
         * @param  ret    Meaning and type of the value assigned to this
         *                parameter depends on the message type (OUT param only, will not be read).
         * @return        Meaning depends on the message type. Returns (uint64)-1 for unknown or not implemented messages.
         */
    virtual std::uint64_t messageSyncData(MessageId msg_id, std::uint64_t key, const void* param, std::uint64_t param_size, const QVariant** ret = nullptr) = 0;

    /**
         * Generic function for sending predefined messages to the host in an asynchronous way without a return value.
         * @param  msg_id Describes the type and semantics of the message.
         *                Check piapi_message_ids.h, namespace "host_msg_async" for valid values and more information about each message.
         * @param  key    Meaning of this parameter depends on the message type. Can be used to select which instance (of many) the message targets.
         * @param  param  Meaning and type of this parameter depends on the message type.
         * @return        Meaning depends on the message type. Returns (uint64)-1 for unknown or not implemented messages.
         */
    virtual std::uint64_t messageAsync(MessageId msg_id, std::uint64_t key, const QVariant* param) = 0;

    /**
         * Generic function to get/set properties or invoke specific functionality.
         * @param  context Used together with item to select the target of the call.
         * @param  item    Used together with context to select the target of the call.
         * @param  param   Meaning and type of this parameter depends on the selected target.
         * @return         Detailed meaning and type depends on the selected target.
         *                 In general, an instance of IfErrorValue is returned to indicate a problem when executing the query.
         *                 Queries that have no defined return value (e.g. property assignment) return nullptr if performed successfully.
         */
    virtual const QVariant* query(const char* context, const char* item, const QVariant* param) = 0;

    /**
         * Optimized version of query that directly accepts an XML document as parameter.
         * Identical to calling query() with an XMLValue containing the same text, but avoids allocation of a new buffer just to transfer the value.
         * @see IfHost::query
         * @param xml_size length of the supplied xml document including the 0-termination character.
         */
    virtual const QVariant* queryXML(const char* context, const char* item, const char* xml, std::uint64_t xml_size) = 0;

protected:
    ~IAppHost() = default; // no virtual destructor to keep the vtable clean
};

#endif // IAPPHOST_H