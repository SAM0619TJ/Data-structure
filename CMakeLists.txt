cmake_minimum_required(VERSION 3.10)
project(ArrayhashMapTest)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 包含头文件目录
include_directories(include)

# 添加可执行文件
add_executable(main 
    src/main.cpp 
    src/hash.cpp
    src/unit_test.cpp
    src/linklist_stack.cpp
)
