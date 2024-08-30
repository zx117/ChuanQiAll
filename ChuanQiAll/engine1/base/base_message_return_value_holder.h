#pragma once

#include "base_if_value.h"
#include "base_api_object_ptr.h"

namespace cq
{

    template <class T>
    class MessageReturnValueHolder
    {
    public:
        MessageReturnValueHolder()
            : m_value(nullptr)
        {
        }
        bool valid() const
        {
            return m_value && m_value->getType() == T::type_index;
        }
        operator bool() const
        {
            return valid();
        }
        const cq::IfValue** data()
        {
            return &m_value;
        }
        const T* operator->()
        {
            return static_cast<const T*>(m_value);
        }
        const T* ref() const
        {
            return static_cast<const T*>(m_value);
        }
        cq::detail::ApiObjectPtr<const T> get() const
        {
            return { ref(), true };
        }

        ~MessageReturnValueHolder()
        {
            if (m_value)
            {
                m_value->release();
            }
        }

    private:
        const cq::IfValue* m_value;
    };

}

