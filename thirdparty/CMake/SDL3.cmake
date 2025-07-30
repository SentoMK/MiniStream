include(ExternalProject)

ExternalProject_Add(SDL3
  SOURCE_DIR ${CMAKE_SOURCE_DIR}/thirdparty/SDL3-src
  CMAKE_ARGS
    -DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/_install/SDL3
    -DSDL_STATIC=OFF
    -DSDL_INSTALL_CMAKE_DIR=lib/cmake/SDL3
    -DCMAKE_BUILD_TYPE=Release
  INSTALL_DIR ${CMAKE_BINARY_DIR}/_install/SDL3
  BUILD_ALWAYS 0
)

# 设置查找 SDL3 的路径
set(SDL3_DIR ${CMAKE_BINARY_DIR}/_install/SDL3/lib/cmake/SDL3)
