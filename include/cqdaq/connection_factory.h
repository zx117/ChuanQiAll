
#pragma once
#include <cqdaq/connection_ptr.h>
#include <cqdaq/signal_ptr.h>
#include <cqdaq/input_port_ptr.h>
#include <cqdaq/context_ptr.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_connection
 * @addtogroup cqdaq_connection_factories Factories
 * @{
 */

/*!
 * @brief Creates a Connection object that acts as a packet queue between the provided Input port and Signal.
 * @param inputPort The input port to which the connection leads.
 * @param signal The signal that is to be connected to an input port.
 * @param context The Context. Most often provided by the Instance.
 */
inline ConnectionPtr Connection(InputPortPtr inputPort, SignalPtr signal, ContextPtr context)
{
    ConnectionPtr obj(Connection_Create(inputPort, signal, context));
    return obj;
}
/*!@}*/

END_NAMESPACE_CQDAQ
