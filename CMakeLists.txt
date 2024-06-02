cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Pi-X-Library)

include_directories(
    "include"

    "lib/type_info"
    "lib/smart_pointer"

    "lib/string"
    "lib/array"
    "lib/stack"
    "lib/queue"
    "lib/deque"
    "lib/hash_table"
    "lib/complex"
    "lib/vector"
    "lib/matrix"
)

add_executable(pix_tester
    tester/main.cpp
)