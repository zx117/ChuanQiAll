#pragma once

#include "api_types.h"

#include "uni_xpugixml_fwd.h"

#include <string>

namespace cq
{

    struct Timebase : equality_comparable<Timebase>
    {
        enum class TimebaseType
        {
            NONE,
            SIMPLE,
        };

        //create a Timebase of type NONE
        Timebase();

        //create a SIMPLE Timebase with a frequency
        explicit Timebase(double frequency);

        //parse any of the supported timebase nodes
        bool parse(pugi::xml_node node);

        //read timebase information from the parent element
        bool extract(pugi::xml_node parent_node);

        //write timebase information as child of parent element
        bool store(pugi::xml_node parent_node) const;

        //generate an XML representation as string
        std::string generate() const;

        bool operator==(const Timebase& other) const;

        void reset();

        TimebaseType m_type;
        double m_frequency;
    };

}
