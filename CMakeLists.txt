cmake_minimum_required(VERSION 3.20)
project(MiniStream LANGUAGES CXX)

# ———— 基本设置 ————
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 可选：允许用户在 cmake 命令行指定第三方库 install 路径
# 示例： cmake -DTHIRD_PARTY_INSTALL_PREFIX=/path/to/thirdparty/install ..
set(THIRD_PARTY_INSTALL_PREFIX
    "${CMAKE_SOURCE_DIR}/thirdparty/install"
    CACHE PATH "Installation prefix for all thirdparty libraries"
)

# 主可执行
add_executable(MiniStream
    app/src/main.cpp
)
target_include_directories(MiniStream PUBLIC
    ${CMAKE_SOURCE_DIR}/include
)

# 把 thirdparty 作为一个子项目
# thirdparty/CMakeLists.txt 会根据 THIRD_PARTY_INSTALL_PREFIX 构建并安装所有子库
add_subdirectory(thirdparty)

# 下面示例：链接第三方库
# target_link_libraries(MiniStream PRIVATE somelib1 somelib2_imported)
