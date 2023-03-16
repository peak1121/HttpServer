#ifndef _COUNTDOWNLATCH_H
#define _COUNTDOWNLATCH_H

#include "base/Condition.h"
#include "base/Mutex.h"

namespace peak
{

class CountDownLatch : noncopyable
{
public:
    explicit CountDownLatch(int count);
    void wait();
    void countDown();
    int getCount() const;
private:
    mutable MutexLock mutex_;
    Condition condition_ ;
    int count_ ;
};

}  // namespace peak


#endif


