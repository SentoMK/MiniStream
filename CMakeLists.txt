cmake_minimum_required(VERSION 3.30)

project(MiniStream)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL3 REQUIRED
    PATHS "D:/sentomk/Dev/Mini/thirdparty/SDL3"
    NO_DEFAULT_PATH
)

set(SDL3_DLL "D:/sentomk/Dev/Mini/thirdparty/SDL3/lib/x64/SDL3.dll")

include_directories(${SDL3_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/include)

add_executable(MiniStream
    src/main.cpp
)

target_link_libraries(MiniStream
    ${SDL3_LIBRARIES}
)

add_custom_command(TARGET MiniStream POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${SDL3_DLL}"
    $<TARGET_FILE_DIR:MiniStream>
)