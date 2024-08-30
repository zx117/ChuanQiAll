/* -*- mode: c++ -*- */
#ifndef __daq_observer_model_h__
#define __daq_observer_model_h__

#include <vector>
#include <string>
#include <algorithm>

///
class Observable;
/**
 * \brief Class Argument.
 *
 * It is a dumy class used to send arguments to the Observer classes
 * subscribed to a given Observable.
 *
 *
 */
class Argument
{
    /// code
    std::string code;
    public:
        /// Default constructor
        Argument()
        {
        }
        ///Constructor
        Argument(const std::string &s) :
            code(s)
            {
            }
        /// Destructor
        virtual ~Argument()
        {
        }
        ;

        /// Retrieves the code
        const std::string &get_code() const
        {
            return code;
        }
        /// Sets the code
        void set_code(const std::string &s)
        {
            code = s;
        }
};

/**
 * This is a template class derived from Argument. It is a handy tool
 * to send arguments to any Observer}.
 *
 * \author  Carlos Lacasta Llacer
 */
template <class T>
class Arg : public Argument
{
    private:
        /// a value
        T value;
    public:
        /// constructor
        Arg(const T &v, const std::string &code = "")
        : Argument(code), value(v)
        {}
        /// Gets the value
        T &get_value()
        {
            return value;
        }
        /// Gets the value
        operator T()
        {
            return value;
        }
        /// Gets the value
        T const &operator()() const
        {
            return value;
        }
};

/**
 * \brief class Observer.
 * This class implements the Observer. Whenever an Observable
 * wants to notify a change, this class will be activated through
 * Observer::update.
 *
 * @author  Carlos Lacasta Llacer
 */
class Observer
{
    public:
        /// destructor
        virtual ~Observer()
        {}
        /// virtual function to connect to an Observable
        virtual void update(Observable *o, Argument *arg) = 0;
};
typedef std::vector<Observer *> ObserverList;

/**
 * \brief class Observable.
 *
 * This is a class that will notify the registered Observers whenever
 * there is a change in it status.
 *
 * \author  Carlos Lacasta Llacer
 */
class Observable
{
    private:
        /// Flag that indicates if there is any change to be notified
        bool changed;
    protected:
        /// Forces a change
        virtual void setChanged()
        {
            changed = true;
        }
        /// Clears the flag
        virtual void clearChanged()
        {
            changed = false;
        }
        /// List of observers
        ObserverList observers;
    public:
        /// Destructor
        Observable() : changed(false) {}
        virtual ~Observable()
        {
        }
        /// Finds and iterator
        ObserverList::iterator find(Observer &o)
        {
            return std::find(begin(),end(),&o);
        }
        ObserverList::iterator begin()
        {
            return observers.begin();
        }
        ObserverList::iterator end()
        {
            return observers.end();
        }
        /// Adds a new observer
        virtual void addObserver(Observer &o)
        {
            observers.push_back(&o);
        }
        /// Removes an observer from the list
        virtual void deleteObserver(Observer &o)
        {
            ObserverList::iterator ip = std::find(observers.begin(),observers.end(), &o);
            if (ip!=observers.end())
                observers.erase(ip);
        }
        /// Deletes the list of observers
        virtual void deleteObservers()
        {
            observers.clear();
        }
        /// Returns the size of the list of Observers
        virtual int  countObservers()
        {
            return static_cast<int>(observers.size());
        }
        /**
         * Checks if there has been any change that deserves to be notified.
         */
        virtual bool hasChanged()
        {
            return changed;
        }
        /// Notifies the changes to the Observers
        virtual void notifyObservers(Argument *arg = 0);

        /// Loops on all the Observers
        template <class _Function>
        _Function for_each_observer(_Function __f)
        {
            ObserverList::iterator ip, last = observers.end();
            for (ip = observers.begin();ip != last;++ip)
                __f( *ip );

            return __f;
        }

        /// List of observers
        ObserverList const &Observers() const
        {
            return observers;
        }
};

inline void Observable::notifyObservers(Argument *arg)
{
    ObserverList::iterator it;
    for (it = observers.begin();it != observers.end();++it)
        (*it)->update(this, arg);

}

#endif
