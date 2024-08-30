
#pragma once
#include <coretypes/baseobject.h>
#include <coretypes/stringobject.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup coretypes
 * @addtogroup types_inspectable
 * @{
 */

/*!
 * @brief Provides introspection into the object providing cqDAQ interface implementations.
 */
DECLARE_CQDAQ_INTERFACE(IInspectable, IBaseObject)
{
    /*!
     * @brief Retrieves the Ids of interfaces this object implements.
     * To find out the number of interfaces implemented and the needed size of the @p ids you can first call
     * the function with the @p ids as @c nullptr which will then only return the size over the @p idCount parameter.
     * @param[out] idCount The number of interfaces implemented.
     * @param[out] ids The interface ids represented as an IntfID struct, if @c nullptr it is not populated. 
     */
    virtual ErrCode INTERFACE_FUNC getInterfaceIds(SizeT* idCount, IntfID** ids) = 0;

    /**
     * @brief Gets the fully qualified name of the cqDAQ object providing the implementation.
     * @param implementationName The actual implementation class name.
     */
    virtual ErrCode INTERFACE_FUNC getRuntimeClassName(IString** implementationName) = 0;
};

/*!@}*/

END_NAMESPACE_CQDAQ
