//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
//
//     RTGen (CppGenerator v5.0.0) on 20.07.2024 00:55:21.
// </auto-generated>
//------------------------------------------------------------------------------
#pragma once
#include <coretypes/coretypes.h>
#include "cqdaq/search_filter.h"
#include <coretypes/objectptr.h>
#include <cqdaq/component_ptr.h>




BEGIN_NAMESPACE_CQDAQ


class SearchFilterPtr;



END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ

template <>
struct InterfaceToSmartPtr<daq::ISearchFilter>
{
    using SmartPtr = daq::SearchFilterPtr;
};


END_NAMESPACE_CQDAQ

BEGIN_NAMESPACE_CQDAQ



/*!
 * @ingroup cqdaq_components
 * @addtogroup cqdaq_components_search_filter Search filter
 * @{

 */


/*!
 * @brief Search filter that can be passed as an optional parameter to cqDAQ tree traversal functions to filter
 * out unwanted results. Allows for recursive searches.

 * Each filter defines an "accepts component" and "visit children" function.
 * Accepts component defines whether or not the component being evaluated as part of a search method should be included
 * in the resulting output.
 * Visit children defines whether or not the children of said component should be traversed during a recursive search.
 */

class SearchFilterPtr : public daq::ObjectPtr<ISearchFilter>
{
public:
    using daq::ObjectPtr<ISearchFilter>::ObjectPtr;
    //using daq::ObjectPtr<ISearchFilter>::operator=;



    SearchFilterPtr()
        : daq::ObjectPtr<ISearchFilter>()

    {
    }

    SearchFilterPtr(daq::ObjectPtr<ISearchFilter>&& ptr)
        : daq::ObjectPtr<ISearchFilter>(std::move(ptr))

    {
    }

    SearchFilterPtr(const daq::ObjectPtr<ISearchFilter>& ptr)
        : daq::ObjectPtr<ISearchFilter>(ptr)

    {
    }

    SearchFilterPtr(const SearchFilterPtr& other)
        : daq::ObjectPtr<ISearchFilter>(other)

    {
    }

    SearchFilterPtr(SearchFilterPtr&& other) noexcept
        : daq::ObjectPtr<ISearchFilter>(std::move(other))

    {
    }
    
    SearchFilterPtr& operator=(const SearchFilterPtr& other)
    {
        if (this == &other)
            return *this;

        daq::ObjectPtr<ISearchFilter>::operator =(other);


        return *this;
    }

    SearchFilterPtr& operator=(SearchFilterPtr&& other) noexcept
    {
        if (this == std::addressof(other))
        {
            return *this;
        }


        daq::ObjectPtr<ISearchFilter>::operator =(std::move(other));

        return *this;
    }


    /*!
     * @brief Defines whether or not the component should be included in the search results

     * @param component The component being evaluated.
     * @returns True of the component is to be included in the results; false otherwise.
     */
    daq::Bool acceptsComponent(const daq::ComponentPtr& component) const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::Bool accepts;
        auto errCode = this->object->acceptsComponent(component, &accepts);
        daq::checkErrorInfo(errCode);

        return accepts;
    }


    /*!
     * @brief Defines whether or not the children of said component should be traversed during a recursive search.

     * @param component The component being evaluated.
     * @returns True of the component's children should be traversed; false otherwise.
     */
    daq::Bool visitChildren(const daq::ComponentPtr& component) const
    {
        if (this->object == nullptr)
            throw daq::InvalidParameterException();

        daq::Bool visit;
        auto errCode = this->object->visitChildren(component, &visit);
        daq::checkErrorInfo(errCode);

        return visit;
    }

#if __has_include(<cqdaq/search_filter_ptr.custom.h>)
    #include <cqdaq/search_filter_ptr.custom.h>
#endif
};

/*!
 * @}
 */


/*!
 * @ingroup cqdaq_components_search_filter
 * @addtogroup cqdaq_components_search_filter_factories Factories
 * @{

 */


/*!
 * @}
 */


END_NAMESPACE_CQDAQ
