
#pragma once
#include <coreobjects/unit_builder_ptr.h>
#include <coretypes/struct_type_factory.h>
#include <coretypes/simple_type_factory.h>

BEGIN_NAMESPACE_CQDAQ

/*!
 * @ingroup coreobjects_unit
 * @addtogroup coreobjects_unit_factories Factories
 * @{
 */


/*!
 * @brief Creates a Unit with its `id`, `symbol`, `name`, and `quantity`
 * fields configured.
 *
 * @param id The unit ID as defined in <a href="https://unece.org/trade/cefact/UNLOCODE-Download">Codes for Units of Measurement used in International Trade</a>.
 * @param symbol The symbol of the unit, i.e. "m/s".
 * @param name The full name of the unit, i.e. "meters per second". (optional)
 * @param quantity The quantity represented by the unit, i.e. "Velocity". (optional)
 */
inline UnitPtr Unit(const StringPtr& symbol, const Int id = -1, const StringPtr& name = "", const StringPtr& quantity = "")
{
    UnitPtr obj(Unit_Create(id, symbol, name, quantity));
    return obj;
}

/*!
 * @brief Creates a Unit with Builder
 * @param builder Unit Builder
 */
inline UnitPtr UnitFromBuilder(const UnitBuilderPtr& builder)
{
    UnitPtr obj(UnitFromBuilder_Create(builder));
    return obj;
}

/*!
 * @brief Creates a UnitBuilder with no parameters configured.
 */
inline UnitBuilderPtr UnitBuilder()
{
    UnitBuilderPtr obj(UnitBuilder_Create());
    return obj;
}

/*!
 * @brief UnitBuilderPtr copy factory that creates a Unit Builder object from a
 * non-configurable UnitPtr.
 * @param unit The Unit of which configuration should be copied.
 */
inline UnitBuilderPtr UnitBuilderCopy(const UnitPtr& unit)
{
    UnitBuilderPtr obj(UnitBuilderFromExisting_Create(unit));
    return obj;
}

/*!
 * @brief Creates the Struct type object that defines the Unit struct.
 */
inline StructTypePtr UnitStructType()
{
    return StructType(
        "unit",
        List<IString>("id", "symbol", "name", "quantity"),
        List<IBaseObject>(-1, "", "", ""),
        List<IType>(SimpleType(ctInt), SimpleType(ctString), SimpleType(ctString), SimpleType(ctString)));
}

/*!@}*/

END_NAMESPACE_CQDAQ
