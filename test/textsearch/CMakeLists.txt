project(textsearch_test)


add_executable(${PROJECT_NAME} 
trie_test.cpp)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} PUBLIC textsearch_lib gtest_main gmock)