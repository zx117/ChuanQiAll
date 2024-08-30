/*
 * MutexPriv.h
 *
 *  Created on: Dec 14, 2010
 *      Author: lacasta
 */

#ifndef MUTEXPRIV_H_
#define MUTEXPRIV_H_

#include "boost/thread/mutex.hpp"

namespace cq
{
    struct MutexPriv_t
    {
        boost::mutex mtx;

        void acquire()
        {
            return mtx.lock();
        }
        void release()
        {
            return mtx.unlock();
        }
    };
};
#endif /* MUTEXPRIV_H_ */
