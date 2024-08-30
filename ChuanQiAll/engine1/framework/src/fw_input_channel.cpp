#include "fw_input_channel.h"

namespace cq
{
namespace framework
{
    void InputChannel::setChannelId(std::uint64_t id)
    {
        m_input_channel_data.m_channel_id = id;
    }

    std::uint64_t InputChannel::getChannelId() const
    {
        return m_input_channel_data.m_channel_id;
    }

    bool InputChannel::isUsable() const
    {
        const auto is_usable = getInputChannelParam<cq::IfBooleanValue>("Usable");
        if (is_usable)
        {
            return is_usable->getValue();
        }

        return false;
    }

    bool InputChannel::isIdValid() const
    {
        return getChannelId() != std::numeric_limits<std::uint64_t>::max();
    }

    cq::ChannelDataformat InputChannel::getDataFormat() const
    {
        return m_input_channel_data.dataformat;
    }

    cq::Timebase InputChannel::getTimeBase() const
    {
        return m_input_channel_data.m_time_base;
    }

    bool InputChannel::updateTimeBase()
    {
        const auto timebase_xml = getInputChannelParam<cq::IfXMLValue>("Timebase");

        if (timebase_xml)
        {
            pugi::xml_document doc;
            auto status = doc.load_string(timebase_xml->getValue());
            if (status.status == pugi::status_ok)
            {
                cq::Timebase timebase;
                if (timebase.extract(doc))
                {
                    m_input_channel_data.m_time_base = timebase;
                    return true;
                }
            }
        }
        return false;
    }

    bool InputChannel::updateDataFormat()
    {
        const auto data_format_xml = getInputChannelParam<cq::IfXMLValue>("DataFormat");
        if (!data_format_xml)
        {
            return false;
        }

        cq::ChannelDataformat dataformat_bak(m_input_channel_data.dataformat);

        if (!m_input_channel_data.dataformat.parse(data_format_xml->asStringView()))
        {
            //corrupt or legacy xml
            const auto data_format_extracted = extractDataFormat(*data_format_xml);
            if (!m_input_channel_data.dataformat.parse(data_format_extracted))
            {
                m_input_channel_data.dataformat = dataformat_bak;
                return false;
            }
        }
        return true;
    }

    cq::Range InputChannel::getRange() const
    {
        if (m_input_channel_data.dataformat.m_sample_value_type ==
            cq::ChannelDataformat::SampleValueType::SAMPLE_VALUE_SCALAR)
        {
            if (const auto range_xml = getInputChannelParam<cq::IfXMLValue>("Range"))
            {
                pugi::xml_document doc;
                auto status = doc.load_string(range_xml->getValue());

                if (status.status == pugi::status_ok)
                {
                    if (const auto range_node = xpugi::getChildNodeByTagName(doc, "ScalarRange"))
                    {
                        if (const auto property_node = xpugi::getChildNodeByTagName(range_node, "RangeValue"))
                        {
                            cq::Property range_property;
                            range_property.readValue(property_node, Version());
                            return range_property.getRangeValue();
                        }
                    }
                }
            }
        }
        else
        {
            if (const auto range_val = getInputChannelConfigParam<cq::IfScalarRange>("Range"))
            {
                cq::Property range_property("Range",
                    cq::Range(range_val->getMin(), range_val->getMax(),
                                    range_val->getMinUnit(), range_val->getMaxUnit()));

                return range_property.getRangeValue();
            }
        }
        return {};
    }

    cq::Scalar InputChannel::getSampleRate() const
    {
        if (m_input_channel_data.dataformat.m_sample_occurrence ==
            cq::ChannelDataformat::SampleOccurrence::SYNC)
        {
            if (const auto sr = getInputChannelParam<cq::IfScalarValue>("SampleRate"))
            {
                return cq::Scalar(sr->getValue(), sr->getUnit());
            }
        }
        return {};
    }

    std::string InputChannel::getUnit() const
    {
        if (const auto unit = getInputChannelParam<cq::IfStringValue>("Unit"))
        {
            return unit->getValue();
        }
        return {};
    }

    std::string InputChannel::getName() const
    {
        if (const auto name = getInputChannelParam<cq::IfStringValue>("Name"))
        {
            return name->getValue();
        }
        return {};
    }

    Property InputChannel::getConfigProperty(const std::string &key) const
    {
        if (isIdValid())
        {
            std::string channel_context = cq::queries::ChuanQiChannels;
            channel_context += "#";
            channel_context += std::to_string(getChannelId());
            channel_context += "#Config#";
            channel_context += key;

            auto xml_value = m_host->getValue<cq::IfXMLValue>(channel_context.c_str(), "ValueXML");

            if(xml_value)
            {
                pugi::xml_document doc;

                auto status = doc.load_string(xml_value->getValue());
                if (status.status == pugi::status_ok)
                {
                    Property property;
                    if(property.readValue(doc.document_element(), {}))
                    {
                        return property;
                    }
                }
            }
        }
        return {};
    }

    std::vector<UpdateConfigTelegram::Constraint> InputChannel::getConfigPropertyConstraints(const std::string &key) const
    {
        std::vector<UpdateConfigTelegram::Constraint> constraints;

        if (isIdValid())
        {
            std::string channel_context = cq::queries::ChuanQiChannels;
            channel_context += "#";
            channel_context += std::to_string(getChannelId());
            channel_context += "#Config#";
            channel_context += key;

            auto xml_value = m_host->getValue<cq::IfXMLValue>(channel_context.c_str(), "ConstraintsXML");

            if(xml_value)
            {
                pugi::xml_document doc;

                auto status = doc.load_string(xml_value->getValue());
                if (status.status == pugi::status_ok)
                {
                    if (strcmp(doc.document_element().name(), "Constraints") == 0)
                    {
                        for (const auto& constraint_node : doc.document_element().children())
                        {
                            auto constraint = UpdateConfigTelegram::Constraint::fromXML(constraint_node);
                            if(constraint.getType() != UpdateConfigTelegram::Constraint::UNKNOWN)
                            {
                                constraints.push_back(constraint);
                            }
                        }
                    }
                }
            }
        }
        return constraints;
    }

    void InputChannel::setConfigProperty(const std::string &key, const Property &property)
    {
        if (isIdValid())
        {
            std::string channel_context = cq::queries::ChuanQiChannels;
            channel_context += "#";
            channel_context += std::to_string(getChannelId());
            channel_context += "#Config#";
            channel_context += key;

            pugi::xml_document doc;
            property.appendValue(doc);
            auto xml_string = xpugi::toXML(doc);

            m_host->queryXML(channel_context.c_str(), "ValueXML", xml_string.c_str(), xml_string.size());
        }
    }

    std::string InputChannel::getLongName() const
    {
        if (const auto name = getInputChannelParam<cq::IfStringValue>("LongName"))
        {
            return name->getValue();
        }
        return {};
    }

    std::string InputChannel::getDefaultName() const
    {
        if (const auto name = getInputChannelParam<cq::IfStringValue>("DefaultName"))
        {
            return name->getValue();
        }
        return {};
    }

    std::string InputChannel::extractDataFormat(const cq::IfXMLValue& xml_value) const
    {
        pugi::xml_document doc;

        auto status = doc.load_string(xml_value.getValue());
        if (status.status == pugi::status_ok)
        {
            auto data_format = doc.document_element();
            std::string xpath = "ChannelDataFormat/Channel/DataFormat";

            auto data_format_node = doc.select_node(xpath.c_str());
            if (data_format_node)
            {
                const auto data_format_xml_str(xpugi::toXML(data_format_node));
                return data_format_xml_str;
            }
        }
        return {};
    }
}
}
