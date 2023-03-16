#include "base/CurrentThread.h"

#include <cxxabi.h>
#include <execinfo.h>
#include <stdlib.h>

namespace peak
{
namespace CurrentThread
{
  //线程全局变量
__thread int t_cachedTid = 0;
__thread char t_tidString[32];
__thread int t_tidStringLength = 6;
__thread const char* t_threadName = "unknown";
static_assert(std::is_same<int, pid_t>::value, "pid_t should be int");

string stackTrace()
{
  string stack;
  const int max_frames = 200;
  void* frame[max_frames];
  int nptrs = ::backtrace(frame, max_frames);//保存各个栈帧地址
  char** strings = ::backtrace_symbols(frame, nptrs);//根据地址转换为符号
  if (strings)
  {
    for (int i = 1; i < nptrs; ++i)//将每个函数符号加入stack，跳过第0个（当前函数）
    {
      stack.append(strings[i]);
      stack.push_back('\n');
    }
    free(strings);
  }
  return stack;
}
}  // namespace CurrentThread
}  // namespace peak
