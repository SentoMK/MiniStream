cmake_minimum_required(VERSION 3.20)
project(MiniStream LANGUAGES CXX)

# ———— 基本设置 ————
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ———— 收集源码 ————
add_executable(MiniStream src/main.cpp)

target_include_directories(MiniStream PUBLIC include)

add_subdirectory(${CMAKE_SOURCE_DIR}/thirdparty/SDL3-src)
