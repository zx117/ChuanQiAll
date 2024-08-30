/* -*- mode: c++ -*- */
#ifndef __daq__execption_h__
#define __daq__execption_h__

#include <exception>
#include <iosfwd>
#include <string>
#include <deque>

namespace cq
{
    /**
     * class Exception
     * \ingroup Tools
     *
     * This is the base class for the DAQ++ exceptions.
     */
    class Exception : public std::exception
    {
        protected:
            /// stores the exception message
            std::string _why;
            static std::deque<char*> messages;
            const char *new_message(const std::string &s) const;
        public:
            /// Constructor
            Exception();

            /// Copy constructor
            Exception(const Exception &e);

            /// Destructor
            virtual ~Exception() throw();
            /** Returns a C-style character string describing the general
                cause of the current error.
             */
            const char* what() const throw();
    };

    /**
     * This is the base of the exceptions thrown when a problem with a
     * parameter is found.
     *
     * \ingroup Tools
     */
    class ParameterException : public Exception
    {
        protected:
            /// Parameter name
            std::string name;
        public:
            /// Constructor
            ParameterException(const std::string &name);

            /// Copy constructor
            ParameterException(const ParameterException &e);

            /// Destructor
            ~ParameterException() throw() ;

            /// returns the paramter name
            std::string get_name() const
            {
                return name;
            }

            /// returns the exception message
            const char* what() const throw();
    };

    /**
     * \brief class ParameterNonExistent.
     * \ingroup Tools
     *
     * Exception thrown when a parameter does not exist.
     */
    class ParameterNonExistent : public ParameterException
    {
        public:
            /// Constructor
            ParameterNonExistent(const std::string &name);

            /// Copy constructor
            ParameterNonExistent(const ParameterNonExistent &e)
            : ParameterException(e)
            {}
    };

    /**
     * \brief class ParameterTypeDoesNotMatch.
     * \ingroup Tools
     *
     * Exception thrown when the parameter type does not match.
     */
    class ParameterTypeDoesNotMatch : public ParameterException
    {
        public:
            /// Constructor
            ParameterTypeDoesNotMatch(const std::string &name);

            /// Copy constructor
            ParameterTypeDoesNotMatch(const ParameterTypeDoesNotMatch &e) :
                ParameterException(e)
                {
                }
    };

    /**
     * \brief call NoMemoryException
     * \ingroup Tools
     * 
     * Exception thrown when failing to allocate memory
     */
    class NoMemoryException : public Exception
    {
        public:
            /// Constructor
            NoMemoryException(const std::string &s);
    };

    /**
     * \brief class IOError
     * \ingroup Tools
     * 
     * Exception thrown when an IO error occurs
     */
    class IOException : public Exception
    {
        public:
            /// Constructor
            IOException(const std::string &s);
    };

}

/// Writes the string representation of the exception
std::ostream &operator<<( std::ostream &os, const cq::Exception &ex);

#endif

