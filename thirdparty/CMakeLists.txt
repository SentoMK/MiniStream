cmake_minimum_required(VERSION 3.16)
project(thirdparty-management NONE)

include(ExternalProject)

# 使用从顶层传入的安装前缀
if(NOT DEFINED THIRD_PARTY_INSTALL_PREFIX)
    set(THIRD_PARTY_INSTALL_PREFIX "${CMAKE_CURRENT_SOURCE_DIR}/install")
endif()

# 遍历所有 *-src 目录
file(GLOB THIRD_SRC_DIRS RELATIVE "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/*-src")

foreach(dir ${THIRD_SRC_DIRS})
    set(src_dir "${CMAKE_CURRENT_SOURCE_DIR}/${dir}")
    string(REGEX REPLACE "-src$" "" lib_name "${dir}")
    set(build_dir "${CMAKE_CURRENT_BINARY_DIR}/${lib_name}-build")

    if(EXISTS "${src_dir}/CMakeLists.txt")
        message(STATUS "[thirdparty] Adding CMake library '${lib_name}'")
        add_subdirectory("${src_dir}" "${build_dir}")

    # 假设子项目在其 CMakeLists 中已定义 install() 和 export()
    # 在此阶段不需做其它事情
    elseif(EXISTS "${src_dir}/Makefile")
        message(STATUS "[thirdparty] Adding Makefile library '${lib_name}' via ExternalProject")
        ExternalProject_Add(${lib_name}
            SOURCE_DIR "${src_dir}"
            BINARY_DIR "${build_dir}"
            BUILD_IN_SOURCE ON
            CONFIGURE_COMMAND ""
            BUILD_COMMAND ${MAKE}
            INSTALL_COMMAND ${MAKE} install
            INSTALL_DIR "${THIRD_PARTY_INSTALL_PREFIX}"
        )

        # 为 ExternalProject 生成 IMPORTED target
        ExternalProject_Get_Property(${lib_name} SOURCE_DIR)
        add_library(${lib_name}_imported STATIC IMPORTED GLOBAL)
        set_target_properties(${lib_name}_imported PROPERTIES
            IMPORTED_LOCATION "${THIRD_PARTY_INSTALL_PREFIX}/lib/lib${lib_name}.a"
            INTERFACE_INCLUDE_DIRECTORIES "${THIRD_PARTY_INSTALL_PREFIX}/include"
        )
        add_dependencies(${lib_name}_imported ${lib_name})

    else()
        message(WARNING "[thirdparty] Skipping '${dir}': no CMakeLists.txt or Makefile")
    endif()
endforeach()
