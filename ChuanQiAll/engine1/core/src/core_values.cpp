
#include "core_values.h"


BooleanValue::BooleanValue(bool value) : m_value(value)
{

}

bool BooleanValue::getValue() const
{
    return m_value;
}

void BooleanValue::set(bool value)
{
    m_value = value;
}


StringValue::StringValue(std::string value)
    : m_value(std::move(value))
{

}

const char* StringValue::getValue() const
{
    return m_value.c_str();
}

int StringValue::getLength() const
{
    return static_cast<int>(m_value.size());
}

void StringValue::set(const char* value)
{
    m_value = value;
}

XmlValue::XmlValue(std::string value)
    : m_value(std::move(value))
{}

const char* XmlValue::getValue() const
{
    return m_value.c_str();
}

int XmlValue::getLength() const
{
    return static_cast<int>(m_value.size());
}

void XmlValue::set(const char* value)
{
    m_value = value;
}



DataBlock::DataBlock(std::string value, std::vector<std::uint8_t> data)
    : m_block_description(std::move(value)), m_block_data(std::move(data))
{

}

cq::IfXMLValue* DataBlock::getBlockDescription() const
{
    return new XmlValue(m_block_description);
}

int DataBlock::dataSize() const
{
    return static_cast<int>(m_block_data.size());
}

const std::uint8_t* DataBlock::data() const
{
    return m_block_data.data();
}

void DataBlock::set(cq::IfXMLValue* descr, const std::uint8_t* data, std::uint32_t length)
{
    m_block_description = descr->getValue();

    m_block_data.resize(length);
    memcpy(m_block_data.data(), data, length);
}


