#pragma once
#include <coretypes/common.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_utility
 * @addtogroup cqdaq_core_events Core Event IDs
 * @{
 */

enum class CoreEventId : uint32_t
{
    PropertyValueChanged = 0,
    PropertyObjectUpdateEnd = 10,
    PropertyAdded = 20,
    PropertyRemoved = 30,
    ComponentAdded = 40,
    ComponentRemoved = 50,
    SignalConnected = 60,
    SignalDisconnected = 70,
    DataDescriptorChanged = 80,
    ComponentUpdateEnd = 90,
    AttributeChanged = 100,
    TagsChanged = 110,
    StatusChanged = 120,
    TypeAdded = 130,
    TypeRemoved = 140,
    DeviceDomainChanged = 150,
};

/*!@}*/

END_NAMESPACE_CQDAQ
