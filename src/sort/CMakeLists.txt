project (sort)

set(SOURCES 
    sort.cpp 
    sort.hpp)

add_library(${PROJECT_NAME}_lib STATIC ${SOURCES})

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}_lib)
target_include_directories(${PROJECT_NAME}_lib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/..)
