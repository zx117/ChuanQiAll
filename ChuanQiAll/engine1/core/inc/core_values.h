#pragma once
#include "base_basic_values.h"
#include <atomic>
#include <vector>

template<typename I>
class ValueBase : public I
{
public:
    ValueBase() : m_ref(1) {}
    virtual ~ValueBase() = default;
    ValueBase(const ValueBase&) = delete;
    ValueBase(ValueBase&&) = delete;

    void PLUGIN_API addRef() const final
    {
         m_ref.fetch_add(1, std::memory_order_relaxed);
    }
    void PLUGIN_API release() const final
    {
        if (m_ref.fetch_sub(1, std::memory_order_release) == 1)
        {
            std::atomic_thread_fence(std::memory_order_acquire);
            delete this;
        }
    }
    constexpr cq::IfValue::Type PLUGIN_API getType() const final { return I::type_index; }
    const char* PLUGIN_API getDebugString() const override { return ""; }
private:
    mutable std::atomic<int> m_ref;
};

class BooleanValue : public ValueBase<cq::IfBooleanValue>
{
public:
    BooleanValue(bool value);
    bool PLUGIN_API getValue() const;
    void PLUGIN_API set(bool value) final;
protected:
    bool m_value;
};

class StringValue : public ValueBase<cq::IfStringValue>
{
public:
    StringValue(std::string value);
    const char* PLUGIN_API getValue() const final;
    int PLUGIN_API getLength() const final;
    void PLUGIN_API set(const char* value) final;
protected:
    std::string m_value;
};

class XmlValue : public ValueBase<cq::IfXMLValue>
{
public:
    XmlValue(std::string value);
    const char* PLUGIN_API getValue() const final;
    int PLUGIN_API getLength() const final;
    void PLUGIN_API set(const char* value);
protected:
    std::string m_value;
};

class DataBlock : public ValueBase<cq::IfDataBlock>
{
public:
    DataBlock(std::string value, std::vector<std::uint8_t> data);
    cq::IfXMLValue* PLUGIN_API getBlockDescription() const final;
    int PLUGIN_API dataSize() const final;
    const std::uint8_t* PLUGIN_API data() const final;
    void PLUGIN_API set(cq::IfXMLValue* descr, const std::uint8_t* data, std::uint32_t length);
protected:
    std::string                     m_block_description;
    std::vector<std::uint8_t>       m_block_data;
};

class DataBlockList : public ValueBase<cq::IfDataBlockList>
{
public:
    DataBlockList(std::string value, std::vector<std::uint8_t> data);
    cq::IfXMLValue* PLUGIN_API getBlockListDescription() const;
    int PLUGIN_API getBlockCount() const;
    cq::IfDataBlock* PLUGIN_API getBlock(int index) const;

    virtual void PLUGIN_API set(cq::IfXMLValue* descr, cq::IfDataBlock** data, std::uint32_t length);
protected:
    std::string                     m_block_list_description;
};
