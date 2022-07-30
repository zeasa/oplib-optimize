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
set(CMAKE_CXX_FLAGS_DEBUG          "-O0 -g3 "          CACHE STRING "Flags used by the CXX compiler during DEBUG builds.")
set(CMAKE_CXX_FLAGS_RELEASE        "-O2 "     CACHE STRING "Flags used by the CXX compiler during RELEASE builds.")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g3 " CACHE STRING "Flags used by the CXX compiler during RELWITHDEBINFO builds.")

option(ENABLE_WERROR "Compile with -Werror enabled (default is OFF)" OFF)
if (ENABLE_WERROR)
    add_compile_options(-Werror)
endif()

add_compile_options(-D_DEBUG_)

find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${OpenMP_EXE_LINKER_FLAGS}")
endif()

set(GTEST_ROOT ${PROJECT_SOURCE_DIR}/3rdparty/gtest)

########################################
# include directory
set(OPLIB_INCLUDE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/include
    ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/argtable3
    ${GTEST_ROOT}/include
)
include_directories(${OPLIB_INCLUDE_DIRS})

#add_custom_target(dgemm ALL
#        COMMAND ${CMAKE_MAKE_PROGRAM}
#        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/intel/dgemm
#        COMMENT "intel mkl dgemm example program")

#add_custom_target(sgemm ALL
#        COMMAND ${CMAKE_MAKE_PROGRAM}
#        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/3rdparty/intel/sgemm_test
#        COMMENT "intel mkl dgemm example program")

########################################
# subdirectories
add_subdirectory(3rdparty/gtest)
add_subdirectory(3rdparty/argtable3)
add_subdirectory(lib)
add_subdirectory(example)
add_subdirectory(test)

enable_testing()
add_test(NAME test_oplib COMMAND test_oplib)
