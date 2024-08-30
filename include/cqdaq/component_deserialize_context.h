
#pragma once
#include <coretypes/baseobject.h>
#include <coretypes/type_manager.h>
#include <cqdaq/component.h>

BEGIN_NAMESPACE_CQDAQ


/*#
 * [interfaceLibrary(ITypeManager, "coretypes")]
 */

DECLARE_CQDAQ_INTERFACE(IComponentDeserializeContext, IBaseObject)
{
    virtual ErrCode INTERFACE_FUNC getParent(IComponent** parent) = 0;
    virtual ErrCode INTERFACE_FUNC getRoot(IComponent** root) = 0;
    virtual ErrCode INTERFACE_FUNC getLocalId(IString** localId) = 0;
    virtual ErrCode INTERFACE_FUNC getContext(IContext** context) = 0;
    virtual ErrCode INTERFACE_FUNC getIntfID(IntfID* intfID) = 0;
    // [arrayArg(newIntfID, 1)]
    virtual ErrCode INTERFACE_FUNC clone(
        IComponent * newParent,
        IString* newLocalId,
        IComponentDeserializeContext** newComponentDeserializeContext,
        IntfID* newIntfID) = 0;
};

CQDAQ_DECLARE_CLASS_FACTORY(
    LIBRARY_FACTORY, ComponentDeserializeContext, IContext*, context, IComponent*, root, IComponent*, parent, IString*, localId, IntfID*, intfID);

END_NAMESPACE_CQDAQ
