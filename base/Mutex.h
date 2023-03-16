#ifndef _MUTEX_H
#define _MUTEX_H

#include "base/CurrentThread.h"
#include "base/noncopyable.h"
#include <assert.h>
#include <pthread.h>

namespace peak
{

class MutexLock : noncopyable
{
  public:
    MutexLock() : holder_(0)
    {
      pthread_mutex_init(&mutex_, NULL);
    }
    ~MutexLock()
    {
      assert(holder_ == 0);
      pthread_mutex_destroy(&mutex_);
    }
    bool isLockedByThisThread() const
    {
      return holder_ == CurrentThread::tid();
    }
    void assertLocked() const
    {
      assert(isLockedByThisThread());
    }
    void lock()
    {
      pthread_mutex_lock(&mutex_);
      assignHolder();
    }
    void unlock()
    {
      unassignHolder();
      pthread_mutex_unlock(&mutex_);
    }
    pthread_mutex_t* getPthreadMutex() 
    {
      return &mutex_;
    }
  private:
    friend class Condition;
    /*
      内部类
    */
    class UnassignGuard : noncopyable
    {
    public:
        explicit UnassignGuard(MutexLock& owner) : owner_(owner)
        {
          owner_.unassignHolder();
        }

        ~UnassignGuard()
        {
          owner_.assignHolder();
        }
    private:
        MutexLock& owner_;
    };

    void unassignHolder()
    {
      holder_ = 0;
    }

    void assignHolder()
    {
      holder_ = CurrentThread::tid();
    }
    pthread_mutex_t mutex_;//互斥锁
    pid_t holder_;//记录持有锁的线程真实id
};

/*
使用RAII的思想封装MutexLock，但是不管理MutexLock的生存期
*/
class MutexLockGuard : noncopyable
{
public:
    explicit MutexLockGuard(MutexLock& mutex) : mutex_(mutex)
    {
      mutex_.lock();
    }
    ~MutexLockGuard()
    {
      mutex_.unlock();
    }
private:
    MutexLock& mutex_;
};

}  // namespace peak


#endif



