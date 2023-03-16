#ifndef _THREAD_H
#define _THREAD_H

#include "base/Atomic.h"
#include "base/CountDownLatch.h"
#include "base/Types.h"

#include <functional>
#include <memory>
#include <pthread.h>

namespace peak
{

class Thread : noncopyable
{
public:
    typedef std::function<void ()> ThreadFunc;

    explicit Thread(ThreadFunc, const string& name = string());

    ~Thread();

    void start();
    int join();

    bool started() const { return started_; }
    pthread_t pthreadId() const { return pthreadId_; }
    pid_t tid() const { return tid_; }
    const string& name() const { return name_; }

    static int numCreated() { return numCreated_.get(); }//原子类型全局变量记录已创建线程数

private:
    void setDefaultName();//设置默认名字为thread i

    bool       started_;
    bool       joined_;
    pthread_t  pthreadId_;//线程id
    pid_t      tid_; //线程真实id
    ThreadFunc func_;//线程回调函数，由用户设置
    string     name_;//线程名字
    CountDownLatch latch_;

    static AtomicInt32 numCreated_;
};

}  // namespace peak

#endif




