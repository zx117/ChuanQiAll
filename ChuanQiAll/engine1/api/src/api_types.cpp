#include "api_types.h"

#include <boost/assign/list_of.hpp>
#include <boost/bimap.hpp>
#include <string>

namespace cq
{
    typedef boost::bimap<DataSetMode, std::string> DataSetModeStringMap;

    static const DataSetModeStringMap DATAMODE_TYPE_MAP = boost::assign::list_of<DataSetModeStringMap::relation>
        (cq::DataSetMode::NORMAL, "NORMAL")
        (cq::DataSetMode::SKIP, "SKIP")
        (cq::DataSetMode::AVERAGE, "AVERAGE")
        (cq::DataSetMode::REDUCED, "REDUCED")
        ;

    typedef boost::bimap<cq::DataSetType, std::string> DataSetTypeStringMap;

    static const DataSetTypeStringMap DATASETTYPE_MAP = boost::assign::list_of<DataSetTypeStringMap::relation>
        (cq::DataSetType::SCALED, "SCALED")
        (cq::DataSetType::RAW, "RAW")
        ;

    typedef boost::bimap<cq::StreamPolicy, std::string> StreamPolicyStringMap;

    static const StreamPolicyStringMap STREAM_POLICY_MAP = boost::assign::list_of<StreamPolicyStringMap::relation>
        (cq::StreamPolicy::EXACT, "EXACT")
        (cq::StreamPolicy::RELAXED, "RELAXED")
        ;

    typedef boost::bimap<cq::StreamType, std::string> StreamTypeStringMap;

    static const StreamTypeStringMap STREAM_TYPE_MAP = boost::assign::list_of<StreamTypeStringMap::relation>
        (cq::StreamType::PUSH, "Push")
        (cq::StreamType::PULL, "Pull")
        ;

    std::string dataSetModeToString(const DataSetMode& mode)
    {
        try
        {
            return DATAMODE_TYPE_MAP.left.at(mode);
        }
        catch (...)
        {
            return "Unknown DataSetMode";
        }
    }

    DataSetMode stringToDataSetMode(const std::string& string)
    {
        try
        {
            return DATAMODE_TYPE_MAP.right.at(string);
        }
        catch (...)
        {
            return DataSetMode::INVALID;
        }
    }

    std::string dataSetTypeToString(const DataSetType& type)
    {
        try
        {
            return DATASETTYPE_MAP.left.at(type);
        }
        catch (...)
        {
            return "Unknown DataSetMode";
        }
    }

    DataSetType stringToDataSetType(const std::string& string)
    {
        try
        {
            return DATASETTYPE_MAP.right.at(string);
        }
        catch (...)
        {
            //! questionable
            return DataSetType::SCALED;
        }
    }

    std::string streamPolicyToString(const StreamPolicy& policy)
    {
        try
        {
            return STREAM_POLICY_MAP.left.at(policy);
        }
        catch (...)
        {
            return "Unknown StreamPolicy";
        }
    }

    StreamPolicy stringToStreamPolicy(const std::string& string)
    {
        try
        {
            return STREAM_POLICY_MAP.right.at(string);
        }
        catch (...)
        {
            return StreamPolicy::EXACT;
        }
    }

    std::string streamTypeToString(const StreamType& type)
    {
        try
        {
            return STREAM_TYPE_MAP.left.at(type);
        }
        catch (...)
        {
            return "Unknown StreamType";
        }
    }

    StreamType stringToStreamType(const std::string& string)
    {
        try
        {
            return STREAM_TYPE_MAP.right.at(string);
        }
        catch (...)
        {
            return StreamType::PUSH;
        }
    }

}

