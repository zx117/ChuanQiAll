

#pragma once
#include <coretypes/common.h>
#include <coretypes/baseobject.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup types_utility
 * @defgroup types_weak_ref WeakRef
 * @{
 */

/*!
 * @brief Represents a weak reference to the object.
 *
 * Obtain a weak reference to the object when you want to store it to a local variable
 * and don't want to increment the reference count. Weak reference will not prevent object
 * destruction. Before the object is used, you must obtain a true reference by calling
 * `getRef` or `getRefAs`.
 *
 * Example
 * @code
 * // get weak reference from obj and store it to weakRef
 * IWeakRef* weakRef;
 * auto err = obj->queryInterface(IWeakRef::ID, reinterpret_cast<void**>(&weakRef));
 * if (CQDAQ_FAILED(err))
 *   return;
 * // .
 * // .
 * // .
 * // get true reference from weak reference
 * // this will fail if the obj reference count dropped to zero and the object was destroyed
 * IBaseObject* newRefToObj;
 * err = weakRef->getRef(&newRefToObj);
 * if (CQDAQ_FAILED(err))
 *   return;
 *
 * // do something with newRefToObj
 * // release it when no longer needed
 * newRefToObj->releaseRef()
 * // .
 * // .
 * // when weak reference is no longer needed, release it
 * weakRef->releaseRef();
 *
 * @endcode
 */
DECLARE_CQDAQ_INTERFACE(IWeakRef, IBaseObject)
{
    /*!
     * @brief Gets a true reference to the object as IBaseObject interface.
     * @param[out] object A true reference to the object.
     *
     * After you get a true reference to the object, you need to call `releaseRef`.
     * on `object` interface.
     */
    virtual ErrCode INTERFACE_FUNC getRef(IBaseObject** object) = 0;
    /*!
     * @brief Gets a true reference to the object with specified interface ID.
     * @param intfID ID of the requested interface
     * @param[out] object A true reference to the object.
     *
     * After you get a true reference to the object, you need to call `releaseRef`.
     * on `object` interface.
     */
    virtual ErrCode INTERFACE_FUNC getRefAs(IntfID intfID, void** object) = 0;
};

/*!
 * @brief Provides support for weak reference on the object.
 *
 * If an object supports weak references, it must implement this interface. Client can get weak
 * reference to the object by calling `getWeakRef`.
 *
 * To implement an object with weak reference support, derive the object from `ImplementationOfWeak`
 * which will automatically provide support for weak references to the object.
 *
 * Example:
 * @code
 * class TestObjectImpl : public ImplementationOfWeak<ITestObject>
 * {
 *    public:
 *    \\ ...
 * @endcode
 */
DECLARE_CQDAQ_INTERFACE(ISupportsWeakRef, IBaseObject)
{
    DEFINE_INTFID("ISupportsWeakRef")

    /*!
     * @brief Gets a weak reference to the object.
     * @param[out] weakRef A weak reference to the object.
     */
    virtual ErrCode INTERFACE_FUNC getWeakRef(IWeakRef** weakRef) = 0;
};

/*!@}*/

END_NAMESPACE_CQDAQ
