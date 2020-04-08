project(sort_bench)

add_executable(${PROJECT_NAME} sort_bench.cpp)

target_link_libraries(${PROJECT_NAME} sort_lib benchmark::benchmark_main )