project(sort_test)


add_executable(${PROJECT_NAME} 
sort_test.cpp)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} PUBLIC sort_lib gtest_main gmock)