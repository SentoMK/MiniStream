cmake_minimum_required(VERSION 3.20)
project(MiniStream LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 指定 SDL3 安装路径
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/SDL3")

# 找 SDL3
find_package(SDL3 REQUIRED CONFIG)

# 声明可执行文件
add_executable(MiniStream
    src/main.cpp
)

# 包含头文件路径
target_include_directories(MiniStream PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/SDL3/include
)

# 链接 SDL3
target_link_libraries(MiniStream PRIVATE SDL3::SDL3)
