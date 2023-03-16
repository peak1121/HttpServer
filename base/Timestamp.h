#ifndef _TIMESTAMP_H
#define _TIMESTAMP_H
#include "base/copyable.h"
#include "base/Types.h"

#include <boost/operators.hpp>

namespace peak
{

/*
封装时间戳，唯一数据成员为微妙数
*/
class Timestamp : public peak::copyable,
                  public boost::equality_comparable<Timestamp>,
                  public boost::less_than_comparable<Timestamp>
{
public:
    //构造函数
    Timestamp() : microSecondsSinceEpoch_(0){}
    explicit Timestamp(int64_t microSecondsSinceEpochArg)
    : microSecondsSinceEpoch_(microSecondsSinceEpochArg)
    {
    }
    void swap(Timestamp& that)
    {
        std::swap(microSecondsSinceEpoch_, that.microSecondsSinceEpoch_);
    }
    string toString() const;
    string toFormattedString(bool showMicroseconds = true) const;
    bool valid() const { return microSecondsSinceEpoch_ > 0; }

    //获取微秒或秒
    int64_t microSecondsSinceEpoch() const { return microSecondsSinceEpoch_; }
    time_t secondsSinceEpoch() const
    { return static_cast<time_t>(microSecondsSinceEpoch_ / kMicroSecondsPerSecond); }

    //静态函数
    static Timestamp now();//通过gettimeofday获取当前时间戳
    static Timestamp invalid()//获取一个无效的时间戳
    {
        return Timestamp();
    }
    static Timestamp fromUnixTime(time_t t)
    {
        return fromUnixTime(t, 0);
    }
    static Timestamp fromUnixTime(time_t t, int microseconds)
    {
        return Timestamp(static_cast<int64_t>(t) * kMicroSecondsPerSecond + microseconds);
    }
    static const int kMicroSecondsPerSecond = 1000 * 1000;

private:
    int64_t microSecondsSinceEpoch_;//唯一数据成员，即微秒数
};

//操作符重载。非成员函数形式
inline bool operator<(Timestamp lhs, Timestamp rhs)
{
  return lhs.microSecondsSinceEpoch() < rhs.microSecondsSinceEpoch();
}

inline bool operator==(Timestamp lhs, Timestamp rhs)
{
  return lhs.microSecondsSinceEpoch() == rhs.microSecondsSinceEpoch();
}

/*
namespace peak中的几个全局工具函数
*/
//获取两个时间戳相差的秒数
inline double timeDifference(Timestamp high, Timestamp low)
{
  int64_t diff = high.microSecondsSinceEpoch() - low.microSecondsSinceEpoch();
  return static_cast<double>(diff) / Timestamp::kMicroSecondsPerSecond;
}

inline Timestamp addTime(Timestamp timestamp, double seconds)
{
  int64_t delta = static_cast<int64_t>(seconds * Timestamp::kMicroSecondsPerSecond);
  return Timestamp(timestamp.microSecondsSinceEpoch() + delta);
}


}// namespace peak

#endif