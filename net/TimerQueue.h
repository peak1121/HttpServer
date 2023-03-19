#ifndef _TIMERQUEUE_H
#define _TIMERQUEUE_H

#include <set>
#include <vector>

#include "base/Mutex.h"
#include "base/Timestamp.h"
#include "net/Callbacks.h"
#include "net/Channel.h"

namespace peak
{
namespace net
{

class EventLoop;
class Timer;
class TimerId;

class TimerQueue : noncopyable
{
 public:
  explicit TimerQueue(EventLoop* loop);
  ~TimerQueue();

  TimerId addTimer(TimerCallback cb, Timestamp when, double interval);

  void cancel(TimerId timerId);

 private:
  typedef std::pair<Timestamp, Timer*> Entry;
  typedef std::set<Entry> TimerList;

  typedef std::pair<Timer*, int64_t> ActiveTimer;
  typedef std::set<ActiveTimer> ActiveTimerSet;

  void addTimerInLoop(Timer* timer);
  void cancelInLoop(TimerId timerId);

  void handleRead();

  std::vector<Entry> getExpired(Timestamp now);
  void reset(const std::vector<Entry>& expired, Timestamp now);

  bool insert(Timer* timer);

  EventLoop* loop_;//定时器队列所属loop
  const int timerfd_;//时间对应文件描述符
  Channel timerfdChannel_;//fd对应的通道方便epoll统一处理

  TimerList timers_;//红黑树维护的升序定时器列表

  ActiveTimerSet activeTimers_;//维护活跃的定时器方便删除
  bool callingExpiredTimers_; //维护到期的定时器（我们暂时不删除到期定时器因为可能重启）
  ActiveTimerSet cancelingTimers_;//待删除定时器可能任务被挂起
};

}  // namespace net
}  // namespace peak
#endif 
