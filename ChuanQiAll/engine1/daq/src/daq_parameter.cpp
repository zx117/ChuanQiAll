/*
 * Parameter.cc
 *
 *  Created on: 29 Dec 2010
 *      Author: lacasta
 */


#include <string>
#include <sstream>
#include <iterator>
#include "daq_parameter.h"

namespace cq
{
    template<typename Type>
    std::string dump_vector( std::vector<Type> &v )
    {
        std::ostringstream os;
        os << "< ";
        std::copy(v.begin(), v.end(), std::ostream_iterator<Type>(os, " "));
        os << ">";
        return os.str();
    }


    template<>
    std::string Par<std::string>::get_as_string()
    {
        return this->value;
    }

    template<>
    std::string Par<char>::get_as_string()
    {
        std::string out;
        out.push_back(this->value);
        return out;
    }

    template<>
    std::string Par<bool>::get_as_string()
    {
        std::ostringstream os;
        os << this->value;
        return os.str();
    }


    template<>
    std::string Par<short>::get_as_string()
    {
        std::ostringstream os;
        os << this->value;
        return os.str();
    }

    template<>

    std::string Par<int>::get_as_string()
    {
        std::ostringstream os;
        os << this->value;
        return os.str();
    }
    template<>
    std::string Par<long>::get_as_string()
    {
        std::ostringstream os;
        os << this->value;
        return os.str();
    }

    template<>
    std::string Par<unsigned char>::get_as_string()
    {
        std::string out;
        out.push_back(this->value);
        return out;
    }

    template<>
    std::string Par<unsigned short>::get_as_string()
    {
        std::ostringstream os;
        os << this->value;
        return os.str();
    }

    template<>

    std::string Par<unsigned int>::get_as_string()
    {
        std::ostringstream os;
        os << this->value;
        return os.str();
    }
    template<>
    std::string Par<unsigned long>::get_as_string()
    {
        std::ostringstream os;
        os << this->value;
        return os.str();
    }

    template<>
    std::string Par<float>::get_as_string()
    {
        std::ostringstream os;
        os << this->value;
        return os.str();
    }


    template<>
    std::string Par<double>::get_as_string()
    {
        std::ostringstream os;
        os << this->value;
        return os.str();
    }

    template<>
    std::string Par< std::vector<bool> >::get_as_string()
    {
        return dump_vector<bool>(this->value);
    }

    template<>
    std::string Par< std::vector<short> >::get_as_string()
    {
        return dump_vector<short>(this->value);
    }

    template<>
    std::string Par< std::vector<int> >::get_as_string()
    {
        return dump_vector<int>(this->value);
    }

    template<>
    std::string Par< std::vector<long> >::get_as_string()
    {
        return dump_vector<long>(this->value);
    }


    template<>
    std::string Par< std::vector<unsigned short> >::get_as_string()
    {
        return dump_vector<unsigned short>(this->value);
    }

    template<>
    std::string Par< std::vector<unsigned int> >::get_as_string()
    {
        return dump_vector<unsigned int>(this->value);
    }

    template<>
    std::string Par< std::vector<unsigned long> >::get_as_string()
    {
        return dump_vector<unsigned long>(this->value);
    }


    template<>
    std::string Par< std::vector<float> >::get_as_string()
    {
        return dump_vector<float>(this->value);
    }


    template<>
    std::string Par< std::vector<double> >::get_as_string()
    {
        return dump_vector<double>(this->value);
    }

//    template<typename Type>
//    std::string Par< std::vector<Type, std::allocator<Type> > >::get_as_string()
//    {
//        return dump_vector<Type>(this->value);
//    }
}
