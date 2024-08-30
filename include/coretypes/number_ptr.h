
#pragma once
#include <coretypes/number.h>
#include <coretypes/objectptr.h>

BEGIN_NAMESPACE_CQDAQ

class NumberPtr;

template <>
struct InterfaceToSmartPtr<INumber>
{
    typedef NumberPtr SmartPtr;
};

/*!
 * @addtogroup types_numerics
 * @{
 */

/*!
 * @brief Represents either a float or an int number.
 *
 * Number is used if data type of the number is not strictly defined, i.e.
 * it can accept a float or an int.
 */
class NumberPtr : public ObjectPtr<INumber>
{
public:
    using ObjectPtr<INumber>::ObjectPtr;

    NumberPtr()
    {
    }

    NumberPtr(ObjectPtr<INumber>&& ptr)
        : ObjectPtr<INumber>(std::move(ptr))
    {
    }

    NumberPtr(const ObjectPtr<INumber>& ptr)
        : ObjectPtr<INumber>(ptr)
    {
    }

    /*!
     * @brief Gets a value stored in the object as a floating point value.
     * @return Stored value as a floating point.
     */
    Float getFloatValue() const
    {
        if (this->object == nullptr)
            throw InvalidParameterException();

        Float value;
        auto errCode = this->object->getFloatValue(&value);
        checkErrorInfo(errCode);

        return value;
    }

    /*!
     * @brief Gets a value stored in the object as an integer value.
     * @return Stored value as an integer.
     */
    Int getIntValue() const
    {
        if (this->object == nullptr)
            throw InvalidParameterException();

        Int value;
        auto errCode = this->object->getIntValue(&value);
        checkErrorInfo(errCode);

        return value;
    }
};

/*!@}*/

END_NAMESPACE_CQDAQ
