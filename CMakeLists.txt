cmake_minimum_required(VERSION 3.20)
project(MiniStream LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

# 包含 thirdparty 构建脚本
include(${CMAKE_SOURCE_DIR}/thirdparty/CMake/SDL3.cmake)
include(${CMAKE_SOURCE_DIR}/thirdparty/CMake/FFmpeg.cmake)

# 查找 SDL3
find_package(SDL3 REQUIRED CONFIG PATHS ${SDL3_DIR})

# 查找 FFmpeg（手动指定头文件和库路径）
set(FFMPEG_ROOT ${CMAKE_BINARY_DIR}/_install/ffmpeg)
file(GLOB FFMPEG_LIBS
  ${FFMPEG_ROOT}/lib/libavformat.so
  ${FFMPEG_ROOT}/lib/libavcodec.so
  ${FFMPEG_ROOT}/lib/libavutil.so
  ${FFMPEG_ROOT}/lib/libswscale.so
)

add_executable(MiniStream src/main.cpp)

target_include_directories(MiniStream PRIVATE
  ${CMAKE_SOURCE_DIR}/include
  ${FFMPEG_ROOT}/include
)

target_link_libraries(MiniStream PRIVATE
  SDL3::SDL3
  ${FFMPEG_LIBS}
)

# 构建依赖
add_dependencies(MiniStream SDL3 FFmpeg)
