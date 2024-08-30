
#pragma once
#include <coretypes/objectptr.h>
#include <coretypes/inspectable.h>
#include <coretypes/string_ptr.h>

BEGIN_NAMESPACE_CQDAQ

class InspectablePtr;

template <>
struct InterfaceToSmartPtr<IInspectable>
{
    typedef InspectablePtr SmartPtr;
};

/*!
 * @ingroup coretypes
 * @addtogroup types_inspectable
 * @{
 */

class InspectablePtr : public ObjectPtr<IInspectable>
{
public:
    using ObjectPtr<IInspectable>::ObjectPtr;

    /**
     * @brief Retrieves the Ids of interfaces this object implements.
     * @return The interface ids implemented without @c IBaseObject and @c IUnknown.
     */
    [[nodiscard]]
    std::vector<IntfID> getInterfaceIds() const
    {
        if (this->object == nullptr)
        {
            throw InvalidParameterException();
        }

        SizeT count{};
        ErrCode errCode = object->getInterfaceIds(&count, nullptr);
        checkErrorInfo(errCode);

        std::vector<IntfID> ids(count);

        IntfID* begin = ids.data();
        errCode = object->getInterfaceIds(&count, &begin);
        checkErrorInfo(errCode);

        return ids;
    }

    /**
    * @brief Gets the fully qualified name of the cqDAQ object providing the implementation.
    * @return The actual implementation class name.
    */
    [[nodiscard]]
    StringPtr getRuntimeClassName() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::StringPtr name;
        auto errCode = this->object->getRuntimeClassName(&name);
        daq::checkErrorInfo(errCode);

        return name;
    }
};

/*!@}*/

END_NAMESPACE_CQDAQ
