project (graph)

set(SOURCES 
    graph.cpp 
    graph.hpp)

add_library(${PROJECT_NAME}_lib STATIC ${SOURCES})
target_include_directories(${PROJECT_NAME}_lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/..)
