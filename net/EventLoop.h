#ifndef _EVENTLOOP_H
#define _EVENTLOOP_H

#include <atomic>
#include <functional>
#include <vector>

#include <boost/any.hpp>

#include "base/Mutex.h"
#include "base/CurrentThread.h"
#include "base/Timestamp.h"
#include "net/Callbacks.h"
#include "net/TimerId.h"

namespace peak
{
namespace net
{

class Channel;
class Poller;
class TimerQueue;

class EventLoop : noncopyable
{
public:
    typedef std::function<void()> Functor;

    //初始化状态和poller、TimerQueue、enentfd和对应Channel以及回调函数等，
    EventLoop();
    //关闭enentfd和对应Channel，将当前线程对应的EventLoop置空
    ~EventLoop();

    //事件循环调用poll，返回活跃通道回调活跃通道的回调函数并执行挂起任务
    void loop();
    //将quit置为true，下次事件循环将会退出，若非所属想检查执行会wakeup
    void quit();

    Timestamp pollReturnTime() const { return pollReturnTime_; }

    int64_t iteration() const { return iteration_; }

    //执行任务，如不是所属线程加入挂起任务队列
    void runInLoop(Functor cb);

    //加入挂起任务队列
    void queueInLoop(Functor cb);

    size_t queueSize() const;

    //定时任务
    TimerId runAt(Timestamp time, TimerCallback cb);
    TimerId runAfter(double delay, TimerCallback cb);
    TimerId runEvery(double interval, TimerCallback cb);

    //取消定时器
    void cancel(TimerId timerId);

    //往eventfd发生信息唤醒线程
    void wakeup();
    void updateChannel(Channel* channel);
    void removeChannel(Channel* channel);
    bool hasChannel(Channel* channel);

    void assertInLoopThread()
    {
      if (!isInLoopThread())
      {
        abortNotInLoopThread();
      }
    }
    bool isInLoopThread() const { return threadId_ == CurrentThread::tid(); }
  
    bool eventHandling() const { return eventHandling_; }

    void setContext(const boost::any& context)
    { context_ = context; }

    const boost::any& getContext() const
    { return context_; }

    boost::any* getMutableContext()
    { return &context_; }

    static EventLoop* getEventLoopOfCurrentThread();

private:
    void abortNotInLoopThread();
    void handleRead();  // waked up
    void doPendingFunctors();

    void printActiveChannels() const; // DEBUG

    typedef std::vector<Channel*> ChannelList;

    bool looping_; /* atomic */
    std::atomic<bool> quit_;
    bool eventHandling_; /* atomic */
    bool callingPendingFunctors_; /* atomic */
    int64_t iteration_;
    const pid_t threadId_;//记录当前EventLoop所属线程真实id
    Timestamp pollReturnTime_;
    std::unique_ptr<Poller> poller_;
    std::unique_ptr<TimerQueue> timerQueue_;
    int wakeupFd_;//eventfd

    std::unique_ptr<Channel> wakeupChannel_;//唤醒线程的唤醒通道用eventfd实现
    boost::any context_;//接受任意类型的上下文

    ChannelList activeChannels_;//活跃通道列表
    Channel* currentActiveChannel_;//当前执行任务的通道

    mutable MutexLock mutex_;
    std::vector<Functor> pendingFunctors_;//保存挂起任务会在下次事件到达之后执行
};

}  // namespace net
}  // namespace peak

#endif  // peak_NET_EVENTLOOP_H
