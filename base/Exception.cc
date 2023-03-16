#include "base/Exception.h"
#include "base/CurrentThread.h"

namespace peak
{

Exception::Exception(string msg)
  : message_(std::move(msg)),
    stack_(CurrentThread::stackTrace())
{
}

}  // namespace muduo
