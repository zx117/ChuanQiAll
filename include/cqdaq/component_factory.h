
#pragma once
#include <cqdaq/component_ptr.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_component
 * @addtogroup cqdaq_component_factories Factories
 * @{
 */

/*!
 * @brief Creates a component.
 * @param context The Context. Most often the creating function-block/device passes its own Context to the Folder.
 * @param parent The parent component.
 * @param localId The local ID of the component.
 * @param className The property object class name of the component.
 */
inline ComponentPtr Component(const ContextPtr& context, const ComponentPtr& parent, const StringPtr& localId, const StringPtr& className = "")
{
    ComponentPtr obj(Component_Create(context, parent, localId, className));
    return obj;
}

/*!@}*/

END_NAMESPACE_CQDAQ
