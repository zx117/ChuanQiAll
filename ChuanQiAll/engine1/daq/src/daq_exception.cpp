#include <iostream>
#include <sstream>
#include <cstring>
#include <algorithm>
//#include <sys/types.h>
//#include <unistd.h>
#include "daq_exception.h"

std::deque<char *> cq::Exception::messages;

const char *cq::Exception::new_message(const std::string &s) const
{
    char *msg;
    if (messages.size()>50)
    {
        msg = messages.front();
        messages.pop_front();
        delete [] msg;
    }
    msg = new char [ s.length() ];
    strcpy(msg, s.c_str());
    messages.push_back( msg );

    return msg;
}


cq::Exception::Exception()
{}

cq::Exception::Exception(const cq::Exception &e)
    : _why(e._why)
{
}

cq::Exception::~Exception() throw()
{}

const char* cq::Exception::what() const throw()
{
    std::ostringstream ostr;
    //ostr << "process (" << getpid() << "): ";
    if (_why.empty() )
        ostr << "daq::Exception";
    else
        ostr << _why;

    return new_message(ostr.str());
}

cq::ParameterException::ParameterException(const std::string &pname):
    name(pname)
{}

cq::ParameterException::ParameterException(const cq::ParameterException &e):
    cq::Exception(e)
{
    name = e.name;
}

const char * cq::ParameterException::what() const throw()
{
    std::ostringstream ostr;
    //ostr << "process (" << getpid() << ") "
    ostr<< _why;

    return new_message(ostr.str());
}

cq::ParameterException::~ParameterException() throw()
{
}

cq::ParameterNonExistent::ParameterNonExistent(const std::string &name)
: ParameterException(name)
{
    std::ostringstream ostr;
    ostr << "Parameter " << get_name() << " does not exist";
    _why = ostr.str();
}
cq::ParameterTypeDoesNotMatch::ParameterTypeDoesNotMatch(const std::string &name)
: ParameterException(name)
{
    std::ostringstream ostr;
    ostr << "Parameter type of "
         << get_name()
         << " does not match"
    ;
    _why = ostr.str();
}

cq::NoMemoryException::NoMemoryException(const std::string &s)
{
    _why = s;
}

cq::IOException::IOException(const std::string &s)
{
    _why = s;
}

std::ostream &operator<<( std::ostream &os, const cq::Exception &ex)
{
    os << ex.what();
    return os;
}
