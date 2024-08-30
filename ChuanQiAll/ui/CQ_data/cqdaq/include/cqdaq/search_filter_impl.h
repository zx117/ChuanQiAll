
#pragma once
#include <cqdaq/search_filter.h>
#include <coretypes/list_factory.h>
#include <cqdaq/component_ptr.h>
#include <cqdaq/search_filter_ptr.h>
#include <cqdaq/recursive_search_ptr.h>


BEGIN_NAMESPACE_CQDAQ

// Filter by Visible

class VisibleSearchFilterImpl final : public ImplementationOf<ISearchFilter>
{
public:
    explicit VisibleSearchFilterImpl();

    ErrCode INTERFACE_FUNC acceptsComponent(IComponent* component, Bool* accepts) override;
    ErrCode INTERFACE_FUNC visitChildren(IComponent* component, Bool* visit) override;
};

// Filter by Required tags

class RequiredTagsSearchFilterImpl final : public ImplementationOf<ISearchFilter>
{
public:
    explicit RequiredTagsSearchFilterImpl(const ListPtr<IString>& requiredTags);

    ErrCode INTERFACE_FUNC acceptsComponent(IComponent* component, Bool* accepts) override;
    ErrCode INTERFACE_FUNC visitChildren(IComponent* component, Bool* visit) override;

private:
    std::unordered_set<std::string> requiredTags;
};

// Filter by Excluded tags

class ExcludedTagsSearchFilterImpl final : public ImplementationOf<ISearchFilter>
{
public:
    explicit ExcludedTagsSearchFilterImpl(const ListPtr<IString>& excludedTags);

    ErrCode INTERFACE_FUNC acceptsComponent(IComponent* component, Bool* accepts) override;
    ErrCode INTERFACE_FUNC visitChildren(IComponent* component, Bool* visit) override;

private:
    std::unordered_set<std::string> excludedTags;
};

// Filter by interface ID

class InterfaceIdSearchFilterImpl final : public ImplementationOf<ISearchFilter>
{
public:
    explicit InterfaceIdSearchFilterImpl(const IntfID& id);

    ErrCode INTERFACE_FUNC acceptsComponent(IComponent* component, Bool* accepts) override;
    ErrCode INTERFACE_FUNC visitChildren(IComponent* component, Bool* visit) override;

private:
    IntfID intfId;
};

// Filter by local ID

class LocalIdSearchFilterImpl final : public ImplementationOf<ISearchFilter>
{
public:
    explicit LocalIdSearchFilterImpl(const StringPtr& localId);

    ErrCode INTERFACE_FUNC acceptsComponent(IComponent* component, Bool* accepts) override;
    ErrCode INTERFACE_FUNC visitChildren(IComponent* component, Bool* visit) override;

private:
    StringPtr localId;
};

// No filter

class AnySearchFilterImpl final : public ImplementationOf<ISearchFilter>
{
public:
    explicit AnySearchFilterImpl();

    ErrCode INTERFACE_FUNC acceptsComponent(IComponent* component, Bool* accepts) override;
    ErrCode INTERFACE_FUNC visitChildren(IComponent* component, Bool* visit) override;
};

// Disjunction

class OrSearchFilterImpl final : public ImplementationOf<ISearchFilter>
{
public:
    explicit OrSearchFilterImpl(const SearchFilterPtr& left, const SearchFilterPtr& right);

    ErrCode INTERFACE_FUNC acceptsComponent(IComponent* component, Bool* accepts) override;
    ErrCode INTERFACE_FUNC visitChildren(IComponent* component, Bool* visit) override;

private:
    SearchFilterPtr left;
    SearchFilterPtr right;
};

// Conjunction

class AndSearchFilterImpl final : public ImplementationOf<ISearchFilter>
{
public:
    explicit AndSearchFilterImpl(const SearchFilterPtr& left, const SearchFilterPtr& right);

    ErrCode INTERFACE_FUNC acceptsComponent(IComponent* component, Bool* accepts) override;
    ErrCode INTERFACE_FUNC visitChildren(IComponent* component, Bool* visit) override;

private:
    SearchFilterPtr left;
    SearchFilterPtr right;
};

// Negation

class NotSearchFilterImpl final : public ImplementationOf<ISearchFilter>
{
public:
    explicit NotSearchFilterImpl(const SearchFilterPtr& filter);

    ErrCode INTERFACE_FUNC acceptsComponent(IComponent* component, Bool* accepts) override;
    ErrCode INTERFACE_FUNC visitChildren(IComponent* component, Bool* visit) override;

private:
    SearchFilterPtr filter;
};

// Custom filter

class CustomSearchFilterImpl final : public ImplementationOf<ISearchFilter>
{
public:
    explicit CustomSearchFilterImpl(const FunctionPtr& acceptsFunction, const FunctionPtr& visitFunction);

    ErrCode INTERFACE_FUNC acceptsComponent(IComponent* component, Bool* accepts) override;
    ErrCode INTERFACE_FUNC visitChildren(IComponent* component, Bool* visit) override;
private:
    FunctionPtr acceptsFunc;
    FunctionPtr visitFunc;
};

// Recursive filter

class RecursiveSearchFilterImpl final : public ImplementationOf<ISearchFilter, IRecursiveSearch>
{
public:
    explicit RecursiveSearchFilterImpl(const SearchFilterPtr& filter);

    ErrCode INTERFACE_FUNC acceptsComponent(IComponent* component, Bool* accepts) override;
    ErrCode INTERFACE_FUNC visitChildren(IComponent* component, Bool* visit) override;
private:
    SearchFilterPtr filter;
};

END_NAMESPACE_CQDAQ
