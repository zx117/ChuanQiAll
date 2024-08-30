
#pragma once
#include <coretypes/struct_type_factory.h>
#include <coretypes/simple_type_factory.h>
#include <cqdaq/device_domain_ptr.h>
#include <coreobjects/unit_factory.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup cqdaq_device_domain
 * @addtogroup cqdaq_device_domain_factories Factories
 * @{
 */

inline DeviceDomainPtr DeviceDomain(const RatioPtr& tickResolution, const StringPtr& origin, const UnitPtr& unit)
{
    DeviceDomainPtr obj(DeviceDomain_Create(tickResolution, origin, unit));
    return obj;
}

inline StructTypePtr DeviceDomainStructType()
{
    return StructType(
        "deviceDomain",
        List<IString>("tickResolution", "origin", "unit"),
        List<IBaseObject>(Ratio(1, 1), "", "", Unit("s", -1, "second", "time")),
        List<IType>(RatioStructType(), SimpleType(ctString), UnitStructType()));
}

/*!@}*/

END_NAMESPACE_CQDAQ
