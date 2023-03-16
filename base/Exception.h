#ifndef _EXCEPTION_H
#define _EXCEPTION_H

#include "base/Types.h"
#include <exception>

namespace peak
{
/*
保存调用栈信息和异常信息
*/
class Exception : public std::exception
{
public:
    Exception(string what);
    ~Exception() noexcept override = default;

    const char* what() const noexcept override
    {
      return message_.c_str();
    }

    const char* stackTrace() const noexcept
    {
      return stack_.c_str();
    }

private:
    string message_;
    string stack_;//通过CurrentThread::stackTrace()函数获取栈帧
};

}  // namespace peak

#endif

