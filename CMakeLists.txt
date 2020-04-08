cmake_minimum_required(VERSION 3.17.0)
project(exercises VERSION 0.1.0)

find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
endif()

set(CMAKE_CXX_STANDARD 17)

include(cmake/compileOptions.cmake)

include(CTest)
enable_testing()

add_subdirectory(lib)

include_directories(src)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(bench)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
