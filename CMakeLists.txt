cmake_minimum_required(VERSION 3.26)
project(search_sort_testbed)

set(CMAKE_CXX_STANDARD 20)
set(SOURCES src/main.cpp src/Timer.cpp src/Random.cpp include/Error_code.h include/Key.h include/List.h
        include/List_functions.h include/Random.h include/search_algorithms.h include/Timer.h include/utility_functions.h src/Ordered_list.cpp include/Ordered_list.h src/Key.cpp include/search_options.h)

add_executable(search_algorithm_testbed ${SOURCES})