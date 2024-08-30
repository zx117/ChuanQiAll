/* -*- mode: c++ -*- */
#ifndef __daq_id_h__
#define __daq_id_h__

#include <string>

namespace cq
{

/**
     * class DAQid.
     *
     * This class implements the way DAQ++ identifies DAQ objects. 
     * The ID is stored as a string, and this class provides a number of
     * ways to retrieve the ID is different formats.
*/
class DAQid
{
private:
    /// internal buffer to store the identifier
    std::string _str;

    /// used internally to implement assignment and copy operators.
    void _cpy(const DAQid &id)
    {
        _str = id._str;
    }
public:
    /// Constructor from a string
    DAQid(std::string const &s);
    /// Constructor form a char pointer
    DAQid(const char *s);
    /// Constructor from an integer
    DAQid(int v);
    /// constructor from a short
    DAQid(short v);
    /// constructor from an unsigned long
    DAQid(unsigned long v);
    /// constructor from un unsigned int
    DAQid(unsigned int);
    /// constructor from an unsigned short
    DAQid(unsigned short v);
    /// Copy constructor
    DAQid(const DAQid &id) : _str(id._str) {}
    /// assignment operator
    DAQid &operator=(const DAQid &id)
    {
        if ( &id != this ) _cpy(id);
        return *this;
    }

    /// retreives ID as a string
    std::string const &str()  const
    {
        return _str;
    }
    /// const version
    std::string const &operator()()  const
    {
        return _str;
    }
    /// conversion operator
    operator int() const;
    /// convertsion operator
    operator unsigned int() const;
    /// conversion operator
    operator unsigned long() const;
    /// conversion operator
    operator unsigned short() const;
    /// conversion operator
    operator const char *() const
    {
        return _str.c_str();
    }
    /// conversion operator
    operator std::string() const
    {
        return _str;
    }
};
}
inline bool operator==(const cq::DAQid &id1, const cq::DAQid &id2)
{
    return (id1.str() == id2.str());
}
inline bool operator<(const cq::DAQid &id1, const cq::DAQid &id2)
{
    return (id1.str() < id2.str());
}
std::ostream &operator<<( std::ostream &os, const cq::DAQid &id);

#endif
