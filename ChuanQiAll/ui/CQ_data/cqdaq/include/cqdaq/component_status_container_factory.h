#pragma once
#include <cqdaq/context_ptr.h>
#include <cqdaq/component_status_container_ptr.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_component_status_container
 * @addtogroup cqdaq_component_status_container_factories Factories
 * @{
 */

/*!
 * @brief Creates a Component status container
 */
inline ComponentStatusContainerPtr ComponentStatusContainer()
{
    ComponentStatusContainerPtr obj(ComponentStatusContainer_Create());
    return obj;
}

/*!@}*/

END_NAMESPACE_CQDAQ
