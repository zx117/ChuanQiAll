#include <sstream>
#include <cstdlib>
#include "daq_id.h"

using namespace cq;
//=====================================================================
// daq_id
//=====================================================================
template <class T>
const std::string &get_string(T v)
{
    std::ostringstream ostr;
    static std::string _str;
    ostr << v;
    _str = ostr.str();
    return _str;
}

static std::string convert_hex(const char *s)
{
    char *tmp;
    std::string out(s);
    // Check it is not a decimal number
    unsigned int v = strtoul(s, &tmp, 0);
    if ( *tmp )
        out = s;
    else
        out = get_string<unsigned int>(v);

    return out;
}

DAQid::DAQid(std::string const &s)
{
    _str = convert_hex(s.c_str());
}

DAQid::DAQid(const char *s)
{
    _str = convert_hex(s);
}

DAQid::DAQid(int v)
{
    _str = get_string<int>(v);
}
DAQid::DAQid(short v)
{
    _str = get_string<short>(v);
}
DAQid::DAQid(unsigned short v)
{
    _str = get_string<unsigned short>(v);
}

DAQid::DAQid(unsigned long v)
{
    _str = get_string<unsigned long>(v);
}

DAQid::DAQid(unsigned int v)
{
    _str = get_string<unsigned int>(v);
}


DAQid::operator int() const
{
    char *tmp;
    int v = strtol(_str.c_str(), &tmp, 0);

    return *tmp ? 0 : v;
}


DAQid::operator unsigned int() const
{
    char *tmp;
    unsigned int v = (unsigned int)strtol(_str.c_str(), &tmp, 0);

    return *tmp ? 0 : v;
}

DAQid::operator unsigned long() const
{
    char *tmp;
    unsigned long v = strtoul(_str.c_str(), &tmp, 0);

    return *tmp ? 0 : v;
}

DAQid::operator unsigned short() const
{
    char *tmp;
    unsigned long v = strtoul(_str.c_str(), &tmp, 0);

    return (unsigned short)( *tmp ? 0 : (v&0xffff) );
}


std::ostream &operator<<( std::ostream &os, const DAQid &id)
{
    os << id.str();
    return os;
}
