#ifndef _LOGGING_H
#define _LOGGING_H

#include "base/LogStream.h"
#include "base/Timestamp.h"

namespace peak
{

class TimeZone;

class Logger
{
public:
    enum LogLevel
    {
      TRACE,
      DEBUG,
      INFO,
      WARN,
      ERROR,
      FATAL,
      NUM_LOG_LEVELS,
    };
    //内部类获取文件名
    class SourceFile
    {
    public:
      template<int N>
      SourceFile(const char (&arr)[N]) : data_(arr), size_(N-1)
      {
        const char* slash = strrchr(data_, '/');
        if (slash)
        {
          data_ = slash + 1;
          size_ -= static_cast<int>(data_ - arr);
        }
      }

      explicit SourceFile(const char* filename) : data_(filename)
      {
        const char* slash = strrchr(filename, '/');
        if (slash)
        {
          data_ = slash + 1;
        }
        size_ = static_cast<int>(strlen(data_));
      }
      const char* data_;
      int size_;
    };

  Logger(SourceFile file, int line);
  Logger(SourceFile file, int line, LogLevel level);
  Logger(SourceFile file, int line, LogLevel level, const char* func);
  Logger(SourceFile file, int line, bool toAbort);
  ~Logger();

  //返回日志对应的输出流
  LogStream& stream() { return impl_.stream_; }

  //静态函数设置和获取日志级别
  static LogLevel logLevel();
  static void setLogLevel(LogLevel level);

  //静态类设置具体的时区、Output、Flush操作
  typedef void (*OutputFunc)(const char* msg, int len);
  typedef void (*FlushFunc)();
  static void setOutput(OutputFunc);
  static void setFlush(FlushFunc);
  static void setTimeZone(const TimeZone& tz);

private:

  class Impl
  {
  public:
      typedef Logger::LogLevel LogLevel;
      Impl(LogLevel level, int old_errno, const SourceFile& file, int line);
      void formatTime();
      void finish();

      Timestamp time_;
      LogStream stream_;
      LogLevel level_;
      int line_;
      SourceFile basename_;
  };

  Impl impl_;

};

//全局函数获取日志级别
extern Logger::LogLevel g_logLevel;

inline Logger::LogLevel Logger::logLevel()
{
  return g_logLevel;
}


//具体的日志接口通过宏定义提供给用户
#define LOG_TRACE if (peak::Logger::logLevel() <= peak::Logger::TRACE) \
  peak::Logger(__FILE__, __LINE__, peak::Logger::TRACE, __func__).stream()
#define LOG_DEBUG if (peak::Logger::logLevel() <= peak::Logger::DEBUG) \
  peak::Logger(__FILE__, __LINE__, peak::Logger::DEBUG, __func__).stream()
#define LOG_INFO if (peak::Logger::logLevel() <= peak::Logger::INFO) \
  peak::Logger(__FILE__, __LINE__).stream()
#define LOG_WARN peak::Logger(__FILE__, __LINE__, peak::Logger::WARN).stream()
#define LOG_ERROR peak::Logger(__FILE__, __LINE__, peak::Logger::ERROR).stream()
#define LOG_FATAL peak::Logger(__FILE__, __LINE__, peak::Logger::FATAL).stream()
#define LOG_SYSERR peak::Logger(__FILE__, __LINE__, false).stream()
#define LOG_SYSFATAL peak::Logger(__FILE__, __LINE__, true).stream()

const char* strerror_tl(int savedErrno);


#define CHECK_NOTNULL(val) \
  ::peak::CheckNotNull(__FILE__, __LINE__, "'" #val "' Must be non NULL", (val))

template <typename T>
T* CheckNotNull(Logger::SourceFile file, int line, const char *names, T* ptr)
{
  if (ptr == NULL)
  {
    Logger(file, line, Logger::FATAL).stream() << names;
  }
  return ptr;
}

}  // namespace peak

#endif 
