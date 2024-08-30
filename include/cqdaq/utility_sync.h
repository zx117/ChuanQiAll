
#pragma once

#include <coretypes/common.h>

BEGIN_NAMESPACE_CQDAQ

#ifndef CQDAQ_THREAD_SAFE

class NoLockMutex
{
public:
    void lock() {};
    void unlock() {};

    NoLockMutex(const NoLockMutex&) = delete;
    NoLockMutex& operator=(const NoLockMutex&) = delete;
};

typedef NoLockMutex mutex;

#else

#include <mutex>

typedef std::mutex mutex;

#endif

class RecursiveMutex
{
public:
    RecursiveMutex(mutex* mt)
        : mt(mt)
    {
    }

    RecursiveMutex()
        : mt(nullptr)
    {
    }

    void lock() const
    {
        if (mt != nullptr)
            mt->lock();
    };

    void unlock() const
    {
        if (mt != nullptr)
            mt->unlock();
    };

private:
    mutex* mt;
};

END_NAMESPACE_CQDAQ
