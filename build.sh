#!/bin/sh

#开启命令显示
set -x

SOURCE_DIR=`pwd`

#若BUILD_DIR为空则赋值-./build
BUILD_DIR=${BUILD_DIR:-./build}
#编译选项包括：Debug Release RelWithDebInfo MinSizeRel
BUILD_TYPE=${BUILD_TYPE:-release}

CXX=${CXX:-g++}

#常见json符号链接方法调试编译过程
ln -sf $BUILD_DIR/$BUILD_TYPE/compile_commands.json

#创建编译目录并进入编译目录执行cmake 设置编译选项 开启之后生成的json文件包含所以编译单元执行的指令

mkdir -p $BUILD_DIR/$BUILD_TYPE \
  && cd $BUILD_DIR/$BUILD_TYPE \
  && cmake \
           -DCMAKE_BUILD_TYPE=$BUILD_TYPE \
           -DCMAKE_EXPORT_COMPILE_COMMANDS=ON \
           $SOURCE_DIR \
  && make $*

