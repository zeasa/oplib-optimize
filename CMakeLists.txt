########################################
cmake_minimum_required(VERSION 2.6)

set (CMAKE_BUILD_TYPE RELEASE)
########################################
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# project
project(OPLIB)
set(OPLIB_ROOT_PATH ${CMAKE_CURRENT_LIST_DIR})
set(LIB_INSTALL_PATH install/lib)
set(BIN_INSTALL_PATH install/bin)

########################################
# language
set(CMAKE_CXX_FLAGS_DEBUG          "-O0 -g3"          CACHE STRING "Flags used by the CXX compiler during DEBUG builds.")
set(CMAKE_CXX_FLAGS_RELEASE        "-O2 "     CACHE STRING "Flags used by the CXX compiler during RELEASE builds.")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g3" CACHE STRING "Flags used by the CXX compiler during RELWITHDEBINFO builds.")
option(ENABLE_WERROR "Compile with -Werror enabled (default is OFF)" OFF)
if (ENABLE_WERROR)
    add_compile_options(-Werror)
endif()

set(GTEST_ROOT ${PROJECT_SOURCE_DIR}/3rdparty/gtest)

########################################
# include directory
set(OPLIB_INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/include
    ${GTEST_ROOT}/include
)
include_directories(${OPLIB_INCLUDE_DIRS})

#add_custom_target(example ALL
#        COMMAND ${CMAKE_MAKE_PROGRAM}
#        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/example/
#        COMMENT "npu assembler example target(riscv-ext binary format)")

########################################
# subdirectories
add_subdirectory(3rdparty/gtest)
add_subdirectory(lib)
add_subdirectory(example)
add_subdirectory(test)

enable_testing()
add_test(NAME test_oplib COMMAND test_oplib)
