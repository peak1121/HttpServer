#ifndef _CURRENTTHREAD_H
#define _CURRENTTHREAD_H

#include "base/Types.h"

namespace peak
{
namespace CurrentThread
{
  //每个线程的全局变量保存线程相关信息
  extern __thread int t_cachedTid;
  extern __thread char t_tidString[32];
  extern __thread int t_tidStringLength;
  extern __thread const char* t_threadName;

  void cacheTid();//在Thread.cc中实现

  inline int tid()
  {
    //__builtin_expect做编译器优化，执行else的可能性大
    if (__builtin_expect(t_cachedTid == 0, 0))
    {
      cacheTid();
    }
    return t_cachedTid;
  }

  inline const char* tidString()
  {
    return t_tidString;
  }

  inline int tidStringLength()
  {
    return t_tidStringLength;
  }

  inline const char* name()
  {
    return t_threadName;
  }

  bool isMainThread();//在Thread.cc中实现

  void sleepUsec(int64_t usec);//在Thread.cc中实现

  string stackTrace();//获取栈帧
}  // namespace CurrentThread
}  // namespace peak

#endif


