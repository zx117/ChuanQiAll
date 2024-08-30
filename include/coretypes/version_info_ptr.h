
#pragma once
#include <coretypes/coretypes.h>
#include <coretypes/version_info.h>

BEGIN_NAMESPACE_CQDAQ

class VersionInfoPtr;

template<>
struct InterfaceToSmartPtr<IVersionInfo>
{
    typedef VersionInfoPtr SmartPtr;
};

/*!
 * @addtogroup types_version_info
 * @{
 */

class VersionInfoPtr : public daq::ObjectPtr<IVersionInfo>
{
public:
    using daq::ObjectPtr<IVersionInfo>::ObjectPtr;
//    using daq::ObjectPtr<IVersionInfo>::operator=;

    VersionInfoPtr()
        : daq::ObjectPtr<IVersionInfo>()
    {
    }

    VersionInfoPtr(daq::ObjectPtr<IVersionInfo>&& ptr)
        : daq::ObjectPtr<IVersionInfo>(std::move(ptr))
    {
    }

    VersionInfoPtr(const daq::ObjectPtr<IVersionInfo>& ptr)
        : daq::ObjectPtr<IVersionInfo>(ptr)
    {
    }

    VersionInfoPtr(const VersionInfoPtr& other)
        : daq::ObjectPtr<IVersionInfo>(other)
    {
    }

    VersionInfoPtr(VersionInfoPtr&& other) noexcept
        : daq::ObjectPtr<IVersionInfo>(std::move(other))
    {
    }

    VersionInfoPtr& operator=(const VersionInfoPtr& other)
    {
        if (this == &other)
            return *this;

        daq::ObjectPtr<IVersionInfo>::operator =(other);
        return *this;
    }

    VersionInfoPtr& operator=(VersionInfoPtr&& other) noexcept
    {
        if (this == std::addressof(other))
        {
            return *this;
        }

        daq::ObjectPtr<IVersionInfo>::operator =(std::move(other));
        return *this;
    }

    SizeT getMajor() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        SizeT major;
        auto errCode = this->object->getMajor(&major);
        daq::checkErrorInfo(errCode);

        return major;
    }

    SizeT getMinor() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        SizeT minor;
        auto errCode = this->object->getMinor(&minor);
        daq::checkErrorInfo(errCode);

        return minor;
    }

    SizeT getPatch() const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        SizeT patch;
        auto errCode = this->object->getPatch(&patch);
        daq::checkErrorInfo(errCode);

        return patch;
    }

};

/*!
 * @}
 */

END_NAMESPACE_CQDAQ
