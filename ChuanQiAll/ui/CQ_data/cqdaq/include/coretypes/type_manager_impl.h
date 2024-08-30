
#pragma once
#include <coretypes/type_manager.h>
#include <coretypes/type_manager_private.h>
#include <coretypes/type_ptr.h>
#include <coretypes/dictobject_factory.h>
#include <coretypes/weakrefobj.h>
#include <coretypes/deserializer.h>
#include <coretypes/procedure_ptr.h>

BEGIN_NAMESPACE_CQDAQ

class TypeManagerImpl : public ImplementationOfWeak<ITypeManager, ITypeManagerPrivate, ISerializable>
{
public:
    TypeManagerImpl();

    ErrCode INTERFACE_FUNC addType(IType* type) override;
    ErrCode INTERFACE_FUNC removeType(IString* name) override;
    ErrCode INTERFACE_FUNC getType(IString* typeName, IType** type) override;
    ErrCode INTERFACE_FUNC getTypes(IList** types) override;
    ErrCode INTERFACE_FUNC hasType(IString* typeName, Bool* hasType) override;

    ErrCode INTERFACE_FUNC setCoreEventCallback(IProcedure* callback) override;
    
    ErrCode INTERFACE_FUNC serialize(ISerializer* serializer) override;
    ErrCode INTERFACE_FUNC getSerializeId(ConstCharPtr* id) const override;

    static ConstCharPtr SerializeId();

    static ErrCode Deserialize(ISerializedObject* ser, IBaseObject* context, IFunction* factoryCallback, IBaseObject** obj);

private:
    DictPtr<IString, IType> types;
    ProcedurePtr coreEventCallback;
    std::unordered_set<std::string> reservedTypeNames;
    std::mutex sync;
};

CQDAQ_REGISTER_DESERIALIZE_FACTORY(TypeManagerImpl)

END_NAMESPACE_CQDAQ
