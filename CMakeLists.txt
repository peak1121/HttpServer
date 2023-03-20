cmake_minimum_required(VERSION 2.6)

project(HttpServer C CXX)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif()

# only build examples if this is the main project
if(CMAKE_PROJECT_NAME STREQUAL "HttpServer")
  option(MUDUO_BUILD_EXAMPLES "Build Muduo examples" ON)
endif()

#设置C++编译选项
set(CXX_FLAGS
 -g
 # -DVALGRIND
 -DCHECK_PTHREAD_RETURN_VALUE
 -D_FILE_OFFSET_BITS=64
 -Wall
 -Wextra
 -Werror
 -Wconversion
 -Wno-unused-parameter
 -Wold-style-cast
 -Woverloaded-virtual
 -Wpointer-arith
 -Wshadow
 -Wwrite-strings
 -march=native
 # -MMD
 -std=c++11
 -rdynamic
 )
 
if(CMAKE_BUILD_BITS EQUAL 32)
  list(APPEND CXX_FLAGS "-m32")
endif()

#将CXX_FLAGS所以出现的分号替换成空格保存到CMAKE_CXX_FLAGS
string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")

#设置DEBUG和RELEASE模式下的编译 选项
set(CMAKE_CXX_FLAGS_DEBUG "-O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG")

#可执行文件和库输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

#查找Boost库
find_package(Boost REQUIRED)


# find_library(BOOSTTEST_LIBRARY NAMES boost_unit_test_framework)
# find_library(BOOSTPO_LIBRARY NAMES boost_program_options)
# find_library(BOOSTSYSTEM_LIBRARY NAMES boost_system)

#包含Boost库头文件
include_directories(${Boost_INCLUDE_DIRS})

include_directories(${PROJECT_SOURCE_DIR})

string(TOUPPER ${CMAKE_BUILD_TYPE} BUILD_TYPE)

message(STATUS "CXX_FLAGS = " ${CMAKE_CXX_FLAGS} " " ${CMAKE_CXX_FLAGS_${BUILD_TYPE}})

#添加子工程
#include_directories(base)
add_subdirectory(base)
#include_directories(net)
add_subdirectory(net)

add_subdirectory(http)

add_executable(myHttpServer MyHttpServer.cc)
target_link_libraries(myHttpServer http)

