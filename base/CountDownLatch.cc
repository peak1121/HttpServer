#include "base/CountDownLatch.h"

using namespace peak;

CountDownLatch::CountDownLatch(int count) : mutex_(), condition_(mutex_), count_(count)
{
}
//等待计数值减为0
void CountDownLatch::wait()
{
  MutexLockGuard lock(mutex_);
  while (count_ > 0)
  {
    condition_.wait();
  }
}
//计数减为0时唤醒等待线程
void CountDownLatch::countDown()
{
  MutexLockGuard lock(mutex_);
  --count_;
  if (count_ == 0)
  {
    condition_.notifyAll();
  }
}
int CountDownLatch::getCount() const
{
  MutexLockGuard lock(mutex_);
  return count_;
}

