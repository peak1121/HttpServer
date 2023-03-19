#ifndef _POLLER_H
#define _POLLER_H

#include "base/Timestamp.h"
#include "net/EventLoop.h"

#include <map>
#include <vector>

#include <assert.h>
#include <errno.h>
#include <poll.h>
#include <sys/epoll.h>
#include <unistd.h>



namespace peak
{
namespace net
{

class Channel;

class Poller : noncopyable
{
 public:
  typedef std::vector<Channel*> ChannelList;
  //构造函数创建epollfd_
  Poller(EventLoop* loop);
  //虚构函数关闭epollfd_
  ~Poller();
  //loop调用poll返回活跃通道
  Timestamp poll(int timeoutMs, ChannelList* activeChannels);


  void updateChannel(Channel* channel);

  void removeChannel(Channel* channel);

  bool hasChannel(Channel* channel) const;

  void assertInLoopThread() const
  {
    ownerLoop_->assertInLoopThread();
  }
private:
  static const int kInitEventListSize = 16;

  static const char* operationToString(int op);

  void fillActiveChannels(int numEvents, ChannelList* activeChannels) const;
  void update(int operation, Channel* channel);

private:
  typedef std::map<int, Channel*> ChannelMap;
  typedef std::vector<struct epoll_event> EventList;

  ChannelMap channels_;//fd作为键值的关注通道列表

  EventLoop* ownerLoop_;//所属loop

  int epollfd_;
  EventList events_;//就绪事件列表
};

}  // namespace net
}  // namespace peak

#endif  // peak_NET_POLLER_H
