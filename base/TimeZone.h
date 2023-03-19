#ifndef _TIMEZONE_H
#define _TIMEZONE_H

#include "base/copyable.h"
#include <memory>
#include <time.h>

namespace peak
{

// TimeZone for 1970~2030
class TimeZone : public peak::copyable
{
 public:
  explicit TimeZone(const char* zonefile);
  TimeZone(int eastOfUtc, const char* tzname); 
  TimeZone() = default;  // an invalid timezone

  bool valid() const
  {
    return static_cast<bool>(data_);
  }

  struct tm toLocalTime(time_t secondsSinceEpoch) const;
  time_t fromLocalTime(const struct tm&) const;

  
  static struct tm toUtcTime(time_t secondsSinceEpoch, bool yday = false);

  static time_t fromUtcTime(const struct tm&);
  // year in [1900..2500], month in [1..12], day in [1..31]
  static time_t fromUtcTime(int year, int month, int day,
                            int hour, int minute, int seconds);
  struct Data;

 private:

  std::shared_ptr<Data> data_;
};

}  // namespace peak

#endif
