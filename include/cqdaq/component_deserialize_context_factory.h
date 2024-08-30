
#pragma once
#include <cqdaq/component_deserialize_context_ptr.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_component
 * @addtogroup cqdaq_component_factories Factories
 * @{
 */

inline ComponentDeserializeContextPtr ComponentDeserializeContext(const ContextPtr& context,
                                                                  const ComponentPtr& root,
                                                                  const ComponentPtr& parent,
                                                                  const StringPtr& localId,
                                                                  IntfID* id = nullptr)
{
    ComponentDeserializeContextPtr obj(ComponentDeserializeContext_Create(context, root, parent, localId, id));
    return obj;
}

/*!@}*/

END_NAMESPACE_CQDAQ
