//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//
//     RTGen (CppGenerator v5.0.0) on 20.07.2024 00:55:45.
// </auto-generated>
//------------------------------------------------------------------------------
#pragma once
#include <coretypes/coretypes.h>
#include "cqdaq/io_folder_config.h"
#include <cqdaq/folder_config_ptr.h>




BEGIN_NAMESPACE_CQDAQ


class IoFolderConfigPtr;



END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ

template <>
struct InterfaceToSmartPtr<daq::IIoFolderConfig>
{
    using SmartPtr = daq::IoFolderConfigPtr;
};


END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ



/*!
 * @ingroup cqdaq_components
 * @addtogroup cqdaq_component IoFolder
 * @{

 */


/*!
 * @brief Acts as a container for channels and other io folders.

 * Every device has an IO folder, which allows only other IO folders and
 * channels as children.
 */

class IoFolderConfigPtr : public GenericFolderConfigPtr<IIoFolderConfig>
{
public:
    using GenericFolderConfigPtr<IIoFolderConfig>::GenericFolderConfigPtr;
    //using GenericFolderConfigPtr<IIoFolderConfig>::operator=;



    IoFolderConfigPtr()
        : GenericFolderConfigPtr<IIoFolderConfig>()

    {
    }

    IoFolderConfigPtr(daq::ObjectPtr<IIoFolderConfig>&& ptr)
        : GenericFolderConfigPtr<IIoFolderConfig>(std::move(ptr))

    {
    }

    IoFolderConfigPtr(const daq::ObjectPtr<IIoFolderConfig>& ptr)
        : GenericFolderConfigPtr<IIoFolderConfig>(ptr)

    {
    }

    IoFolderConfigPtr(const IoFolderConfigPtr& other)
        : GenericFolderConfigPtr<IIoFolderConfig>(other)

    {
    }

    IoFolderConfigPtr(IoFolderConfigPtr&& other) noexcept
        : GenericFolderConfigPtr<IIoFolderConfig>(std::move(other))

    {
    }
    
    IoFolderConfigPtr& operator=(const IoFolderConfigPtr& other)
    {
        if (this == &other)
            return *this;

        GenericFolderConfigPtr<IIoFolderConfig>::operator =(other);


        return *this;
    }

    IoFolderConfigPtr& operator=(IoFolderConfigPtr&& other) noexcept
    {
        if (this == std::addressof(other))
        {
            return *this;
        }


        GenericFolderConfigPtr<IIoFolderConfig>::operator =(std::move(other));

        return *this;
    }




#if __has_include(<cqdaq/io_folder_config_ptr.custom.h>)
    #include <cqdaq/io_folder_config_ptr.custom.h>
#endif
};

/*!
 * @}
 */


END_NAMESPACE_CQDAQ
