#pragma once
#include <coretypes/coretypes.h>
#include <coreobjects/property_object_class.h>
#include <coreobjects/property_object_class_builder.h>
#include <coreobjects/property_object_class_builder_ptr.h>
#include <coreobjects/property_ptr.h>
#include <coretypes/type_manager_ptr.h>
#include <coreobjects/object_keys.h>
#include <tsl/ordered_map.h>
#include <vector>

BEGIN_NAMESPACE_CQDAQ

struct ISerializedObject;

using PropertyOrderedMap = tsl::ordered_map<StringPtr, PropertyPtr, StringHash, StringEqualTo>;

class PropertyObjectClassImpl : public ImplementationOf<IPropertyObjectClass, ISerializable>
{
public:
    explicit PropertyObjectClassImpl(IPropertyObjectClassBuilder* builder);

    // IPropertyObjectClass

    ErrCode INTERFACE_FUNC getName(IString** typeName) override;
    ErrCode INTERFACE_FUNC getParentName(IString** parentName) override;
    ErrCode INTERFACE_FUNC getProperty(IString* propertyName, IProperty** property) override;
    ErrCode INTERFACE_FUNC hasProperty(IString* propertyName, Bool* hasProperty) override;
    ErrCode INTERFACE_FUNC getProperties(Bool includeInherited, IList** properties) override;

    ErrCode INTERFACE_FUNC serialize(ISerializer* serializer) override;
    ErrCode INTERFACE_FUNC getSerializeId(ConstCharPtr* id) const override;

    ErrCode INTERFACE_FUNC toString(CharPtr* str) override;

    static ConstCharPtr SerializeId();
    static ErrCode Deserialize(ISerializedObject* serialized, IBaseObject* context, IFunction* factoryCallback, IBaseObject** obj);

private:
    StringPtr name;
    StringPtr parent;
    PropertyOrderedMap props;
    std::vector<StringPtr> customOrder;
    WeakRefPtr<ITypeManager> manager;

    ErrCode getManager(TypeManagerPtr& managerPtr) const;
    ErrCode getWithNormalOrder(Bool includeInherited, IList** list);
    ErrCode getWithCustomOrder(Bool includeInherited, IList** list);
    ErrCode getInheritedProperties(ListPtr<IProperty>& properties) const;
    
    ErrCode serializeProperties(ISerializer* serializer);

    bool hasDuplicateReferences(const PropertyPtr& prop);
};


CQDAQ_REGISTER_DESERIALIZE_FACTORY(PropertyObjectClassImpl)

END_NAMESPACE_CQDAQ
