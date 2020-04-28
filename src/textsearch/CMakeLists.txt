project (textsearch)

set(SOURCES 
    textsearch.hpp 
    trie.hpp)

add_library(${PROJECT_NAME}_lib INTERFACE)
target_include_directories(${PROJECT_NAME}_lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/..)

