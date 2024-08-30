
#pragma once
#include <coretypes/struct_builder.h>
#include <coretypes/intfs.h>
#include <coretypes/string_ptr.h>
#include <coretypes/dictobject_factory.h>
#include <coretypes/baseobject_factory.h>
#include <coretypes/struct_ptr.h>
#include <coretypes/type_manager_ptr.h>
#include <coretypes/struct_type_factory.h>
#include <coretypes/stringobject_factory.h>
#include <coretypes/simple_type_factory.h>

BEGIN_NAMESPACE_CQDAQ

class StructBuilderImpl : public ImplementationOf<IStructBuilder>
{
public:
    explicit StructBuilderImpl(const StringPtr& name, const TypeManagerPtr& typeManager);
    explicit StructBuilderImpl(const StructPtr& struct_);

    ErrCode INTERFACE_FUNC build(IStruct** struct_) override;
    ErrCode INTERFACE_FUNC getStructType(IStructType** type) override;
    ErrCode INTERFACE_FUNC getFieldNames(IList** names) override;
    ErrCode INTERFACE_FUNC setFieldValues(IList* values) override;
    ErrCode INTERFACE_FUNC getFieldValues(IList** values) override;
    ErrCode INTERFACE_FUNC set(IString* name, IBaseObject* field) override;
    ErrCode INTERFACE_FUNC get(IString* name, IBaseObject** field) override;
    ErrCode INTERFACE_FUNC hasField(IString* name, Bool* contains) override;
    ErrCode INTERFACE_FUNC getAsDictionary(IDict** dictionary) override;

protected:

    StructTypePtr structType;
    DictPtr<IString, IBaseObject> fields;
};

END_NAMESPACE_CQDAQ
