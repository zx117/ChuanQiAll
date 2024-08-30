/* -*- mode: c++ -*- */
#ifndef __daq_parameter_h__
#define __daq_parameter_h__
#include <iosfwd>
#include <map>
#include <vector>
#include <daq_id.h>
#include <daq_observer_model.h>
#include <daq_exception.h>


namespace cq
{
   /*!
     \page ParametersPage The DAQ++ Parameters

     A Parameter is a named property or parameter. It usually belongs to
     a DAQObject, which is defined to inherit from ParameterHolder the
     ability to stored a collection of these parameters.  A Parameter
     is an Observable, so it also provides a mechanism to monitor the
     values and to react to changes.

     Parameter objects represent a very nice method of accessing
     DAQObject properties in DAQ++ ports to other languages like
     python, where parameters are considered like python object
     attributes.

     The class Parameter defines the interface. Now, since C++ is a
     typed language, we define the C++ template class Par. There are a
     couple of functions defined to simplify the operation with
     generic Parameter objects. These are 
     - DAQpp::get_par_value
     - DAQpp::set_par_value

     This function will check that the required type matches the Parameter
     type. IF it does not match they will throw the DAQpp::ParameterTypeDoesNotMatch
     exception.

     When a DAQObject has more than one Parameter, the administrative burden
     is not negligible anymore. On top of that, we may be interested in
     retrieving or setting the values by name, instead of having a set of
     getter and setter methods. The class ParameterHolder comes to the help
     here. It is implemented as a map where the ky is the Parameter name and
     the value is the Parameter pointer.
   */

    /**
     *  \brief class Parameter.
     *  \ingroup Parameters
     *
     *  This class represents a parameter or property of a DAQObject.
     *  It is a dummy class to define the protocol for parameter
     *  definition inside a DAQObject.
     *
     *  Parameters are names values which have associated a DAQid
     *  which, usually, corresponds to the DAQid of the DAQObject
     *  owning this property. Parameter objects can be of any type.
     *
     *  It derives from Observable and it will notify to any Observer
     *  of any change on the parameter.
     *
     *
     */
    class Parameter : public Observable
    {
        private:
            /// Name of the parameter
            std::string name;
            /// ID of the parameter. This usually corresponds to the DAQid
            /// of the DAQObject owning this property.
            DAQid  _id;
        public:
            /// Constructor
            Parameter() : name("unnamed"), _id("???")
            {}
            /// Destructor
            virtual ~Parameter()
            {
                deleteObservers();
            }
            /// Changes the name of the parameter
            void set_name(const std::string &s)
            {
                name = s;
            }
            /// Returns the current name of the parameter
            const std::string &get_name() const
            {
                return name;
            }

            /// Returns the id.
            DAQid const & get_id() const
            {
                return _id;
            }
            /// Changes the id of the parameter
            void set_id( const DAQid &s )
            {
                _id = s;
            }
            /**
             *  Sets the value from a string.
             *  In this interface it is a dummy function. Each implementation of a
             *  Parameter should provide a way of creating a parameter value from
             *  a string.
             */
            virtual void set_from_string(const std::string &s, bool notify = false)
            {}

            /**
             *  Returns the string representation of the parameter. This should be
             */
            virtual std::string get_as_string()
            {
                return std::string("???");
            }

    };

    /**
     * \ingroup Parameters
     *  \brief class Par<T>.
     *
     *  This is a template class derived from Parameter. It is used to
     *  define parameters with a specific type inside a DAQObject. It provides
     *  the methods to get/set the value of the property
     */
    template <class T>
    class Par : public Parameter
    {
        public:
            /// The type of the parameter value
            typedef T value_type;
        private:
            /// A value
            T value;
        public:
            /// Default Constructor
            Par()
            {}
            /// Another constructor
            Par(const T &v) : value(v)
            {}
            /// Copy constructor
            Par(const Par &v)
            {
                value = v.value;
            }
            /// Assignment operator
            Par &operator=(const Par &v)
            {
                if ( &v == this ) return *this;
                value = v.value;
                return *this;
            }
            /// Destructor.
            ~Par() {}

            /// Sets the value
            void set_value( const T &x, bool notify = false)
            {
                value = x;
                if ( notify )
                {
                    Arg<T> arg(value);
                    notifyObservers(&arg);
                }
            }
            /// Returns the value as const
            T const &operator()() const
            {
                return value;
            }
            /// Returns the value
            T &operator()()
            {
                return value;
            }
            /// Another way of getting the value
            const T & get_value() const
            {
                return value;
            }
            /// Yet another way of getting the value
            T &get_value()
            {
                return value;
            }
            virtual std::string get_as_string()
            {
                return std::string(".oOo.");
            }

    };

    /**
     * \ingroup Parameters
     *  Handy wrapper to get a Par<T> from a generic Parameter
     */
    template<class T>
    T &get_par_value(Parameter *p) throw(ParameterTypeDoesNotMatch )
    {

        Par<T> *t =  dynamic_cast<Par<T> * > (p);
        if ( t == 0 )
            throw ( ParameterTypeDoesNotMatch( p->get_name().c_str() ) );

        return t->get_value();
    }

    /**
     * \ingroup Parameters
     * Handy wrapper to set a Par<T> from a generic Parameter
     */
    template<class T>
    void set_par_value(Parameter *p, const T &v, bool notify = false)
    throw( ParameterTypeDoesNotMatch )
    {
        Par<T> *t =  dynamic_cast<Par<T> * > (p);
        if ( t == 0 )
            throw ( ParameterTypeDoesNotMatch( p->get_name().c_str() ) );
        t->set_value(v, notify);
    }

    /**\brief class ParameterHolder.
     * \ingroup DAQ Parameters
     * \ingroup Parameters
     * 
     * This class represents a holder for named parameters. It is
     * implemented as a named list (a map).  The idea behind is that
     * the class will \em observe all the parameters in the list and
     * will notify changes in any of the parameters.  It delegates
     * some of the Observable functionality to a real one that checks
     * for any change on the parameters
     */
    class ParameterHolder : public std::map<std::string, Parameter *>
    {
        private:
            /** \brief class LocalObserver
             * This class is a real observer that will notify of changes
             * of any of the parameters in the list. This is an internal
             * class only used by ParameterHolder.
             *
             * It has two members, a pointer to the ParameterHolder it belongs to and
             * a pointer to the Observable (in this case a Parameter), that sends a notification.
             */
            class LocalObserver : public Observer, public Observable
            {
                private:
                    /// ParameterHolder it belongs to
                    ParameterHolder *H;
                    /// Pointer to the observer sending the notification message
                    Observable *O;
                public:
                    /**
                     *  Constructor
                     *  @param h The reference of the ParameterHolder
                     */
                    LocalObserver(ParameterHolder &h): H(&h), O(0) {}

                    /**
                     * Update method
                     */
                    void update(Observable *o, Argument *arg)
                    {
                        O = o;
                        notifyObservers(arg);
                    }

                    /**
                     * Sends notification to all the Observers
                     */
                    void notifyObservers(Argument *arg)
                    {
                        ObserverList::iterator it;
                        for (it = observers.begin();it != observers.end();++it)
                            (*it)->update(O, arg);
                    }

                    ParameterHolder *get_holder() const { return H; }
            };
            /// The LocalObserver \em observing the parameters
            LocalObserver observer;
        public:
            // Constructor
            ParameterHolder() : observer(*this)
            {}

            // Destructor
            virtual ~ParameterHolder()
            {
                iterator ip;
                for (ip = begin();ip != end();++ip)
                {
                    ip->second->deleteObservers();
                    delete ip->second;
                }
                clear();
            }

            /// adds a new Observer for the parameter collection
            void addObserver(Observer &o)
            {
                observer.addObserver(o);
            }

            /// Removes one Observer
            void deleteObserver(Observer &o)
            {
                observer.deleteObserver(o);
            }

            /// returns a Parameter with a given name
            Parameter *get_par(const char *par)
            throw( ParameterNonExistent )
            {
                iterator ip = find(par);

                if (ip == end() )
                {
                    throw ( cq::ParameterNonExistent(par) );
                }
                else
                    return ip->second;
            }

            /// Adds a new parameter
            virtual void add_par(const char *pnam, Parameter *par, const DAQid *id = 0)
            {
                (*this)[pnam] = par;
                par->set_name(pnam);
                if (id)
                    par->set_id(*id);

                par->addObserver(observer);
            }

            /// Gets the value of a parameter
            template <class T>
            T &get_par_value(const char *par_name)
            throw( ParameterNonExistent, ParameterTypeDoesNotMatch )
            {
                Parameter *par = get_par(par_name);
                Par<T> *t =  dynamic_cast<Par<T> * > (par);
                if ( t == 0 )
                    throw ( ParameterTypeDoesNotMatch( par_name ) );

                return t->get_value();
            }

            /// Sets the value of a parameter
            template<class T>
            void set_par(const char *pnam, const T &value, bool notify = false)
            throw ( ParameterNonExistent, ParameterTypeDoesNotMatch )
            {
                try
                {
                    Parameter *par = get_par(pnam);
                    set_par_value<T>(par, value, notify);
                }
                catch (...)
                {
                    throw;
                }
            }
            /**
             * Tell if it has a parameter names as given
             */
            bool has_par(const std::string &name)
            {
                ParameterHolder::iterator ip = find(name);
                return  (ip==end() ? false : true);
            }

    };

    /**
     * \ingroup Parameters
     *  This class is a sort of bridge between a parameter Observer and
     *  your class having the Parameter. The class is an observer of a
     *  given parameter that will call a given method of your class when
     *  the parameter changed. That method should only accept one
     *  argument, which is the new value of the Parameter.
     */
    template<typename T, typename C>
    class ParameterObserver : public Observer
    {
        public:
            /// The method signature
            typedef void (C::*method_type)(const T&);
        private:
            /// A pointer to the class registering to the service
            C *module;

            /// A pointer to the class method: the callback function
            void (C::*func)(const T &);

            /// A pointer to the parameter
            cq::Par< T > *par;
        public:

            /// Constructor
            ParameterObserver(C *m, void (C::*f)(const T&), cq::Par< T > *p = 0)
            : module(m), func(f), par(0)
            {
                if (p)
                    set_par(p);
            }

            /// Destructor
            ~ParameterObserver()
            {
                par->deleteObserver( *dynamic_cast<Observer *>(this) );
            }

            /// Changes the Parameter to be \em observed
            void set_par( cq::Par< T > *p)
            {
                if (par)
                    par->deleteObserver( *dynamic_cast<Observer *>(this) );

                par = p;
                par->addObserver( *dynamic_cast<Observer *>(this) );
            }

            /// Returns a pointer to the class
            const C *get_module() const
            {
                return module;
            }


            void update(Observable *o, Argument *arg)
            {
                Arg<T> *v = static_cast< Arg<T> * > (arg);
                (module->*func)( v->get_value() );
            }
    };

    /**
     * \ingroup Parameters
     * This class is a collection of ParameterObservers that also handles
     * the creation of those objects. To use it make your class derive
     * from this one and call new_par for each new parameter that you want
     * to connect to one of your class' methods.
     *
     * This is an example of such a class. It is a ParameterHolder that defines
     * through the ParameterCollection a number of callbacks to monitor changes
     * in its parameters.
     * \code
     * class ParamBridge: public DAQpp::ParameterHolder,
     *                    public DAQpp::ParameterCollection<ParamBridge>
     *  {
     *  public:
     *      ParamBridge();
     *
     *      void change_state(const int &);
     *      void change_value(const double &);
     *      void change_name(const std::string &);
     *  };
     *  ParamBridge::ParamBridge()
     *          :  DAQpp::ParameterCollection<ParamBridge>(this)
     *  {
     *      add_par( "state",
     *               new_par<int>(&ParamBridge::change_state,
     *                            new DAQpp::Par<int>(0)));
     *
     *      add_par( "value",
     *               new_par<double>(&ParamBridge::change_value,
     *                               new DAQpp::Par<double>(0.)));
     *
     *      add_par( "name",
     *               new_par<std::string>(&ParamBridge::change_name,
     *                                    new DAQpp::Par<std::string>("name")));
     *  }
     *  void ParamBridge::change_state(const int &value)
     *  {
     *      std::cout << "...ParamBridge: parameter state changed to "
     *                << value
     *                << std::endl;
     *  }
     *  void ParamBridge::change_value(const double &value)
     *  {
     *      std::cout << "...ParamBridge: parameter value changed to "
     *                << value
     *                << std::endl;
     *  }
     *  void ParamBridge::change_name(const std::string &value)
     *  {
     *      std::cout << "...ParamBridge: parameter name changed to '"
     *                << value << "'"
     *                << std::endl;
     *  }
     *
     * \endcode
     */
    template<typename C>
    class ParameterCollection : std::vector<Observer *>
    {
        private:
            /// A pointer to the class
            C *module;

        public:
            /// Constructor
            ParameterCollection(C *m) : module(m)
            {}

            /// Destructor
            ~ParameterCollection()
            {
                std::vector<Observer *>::iterator ip;
                for (ip = begin(); ip != end(); ++ip)
                {
                    delete *ip;
                }
            }

            /// Adds a new callback function associated to a given Parameter
            template<typename T>
            cq::Par<T> *new_par( void (C::*f)(const T&), cq::Par< T > *p = 0)
            {
                push_back( new ParameterObserver<T, C>(module, f, p) );
                return p;
            }
    };
    template<>
    std::string Par<std::string>::get_as_string();

    template<>
    std::string Par<char>::get_as_string();

    template<>
    std::string Par<bool>::get_as_string();


    template<>
    std::string Par<short>::get_as_string();

    template<>
    std::string Par<int>::get_as_string();

    template<>
    std::string Par<long>::get_as_string();

    template<>
    std::string Par<unsigned char>::get_as_string();

    template<>
    std::string Par<unsigned short>::get_as_string();

    template<>
    std::string Par<unsigned int>::get_as_string();

    template<>
    std::string Par<unsigned long>::get_as_string();

    template<>
    std::string Par<float>::get_as_string();


    template<>
    std::string Par<double>::get_as_string();

    template<>
    std::string Par< std::vector<bool> >::get_as_string();

    template<>
    std::string Par< std::vector<short> >::get_as_string();

    template<>
    std::string Par< std::vector<int> >::get_as_string();

    template<>
    std::string Par< std::vector<long> >::get_as_string();

    template<>
    std::string Par< std::vector<unsigned short> >::get_as_string();

    template<>
    std::string Par< std::vector<unsigned int> >::get_as_string();

    template<>
    std::string Par< std::vector<unsigned long> >::get_as_string();

    template<>
    std::string Par< std::vector<float> >::get_as_string();

    template<>
    std::string Par< std::vector<double> >::get_as_string();

}

#endif
