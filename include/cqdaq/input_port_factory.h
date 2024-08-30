
#pragma once
#include <cqdaq/input_port_config_ptr.h>
#include <cqdaq/context_ptr.h>
#include <cqdaq/input_port_notifications_ptr.h>

BEGIN_NAMESPACE_CQDAQ
/*!
 * @ingroup cqdaq_input_port
 * @addtogroup cqdaq_input_port_factories Factories
 * @{
 */

/*!
 * @brief Creates an input port.
 * @param context The Context. Most often the creating function-block passes its own Context to the Folder.
 * @param parent The parent component.
 * @param localId The local ID of the component.
 */
inline InputPortConfigPtr InputPort(const ContextPtr& context, const ComponentPtr& parent, const StringPtr& localId)
{
    return { InputPort_Create(context, parent, localId) };
}

/*!@}*/

END_NAMESPACE_CQDAQ
