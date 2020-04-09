project (graph)

set(SOURCES 
    graph.cpp 
    graph.hpp)

add_library(${PROJECT_NAME}_lib STATIC ${SOURCES})
