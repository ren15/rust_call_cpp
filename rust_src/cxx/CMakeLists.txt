cmake_minimum_required(VERSION 3.15)
project(math_c)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_C_FLAGS "-O3 -ffast-math -march=native ${CMAKE_C_FLAGS}")
set(CMAKE_C_FLAGS "-Wall -Wextra -Wconversion -Wshadow -Wpedantic ${CMAKE_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} ${CMAKE_CXX_FLAGS}")

# set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fsanitize=address,undefined")
# set(CMAKE_CXX_CLANG_TIDY "clang-tidy")

# --------------------------------------
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


IF(EXISTS "${CMAKE_BINARY_DIR}/conanbuildinfo.cmake")
    INCLUDE(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup(NO_OUTPUT_DIRS)
ENDIF()

set(BENCHMARK_FOLDER "${CMAKE_SOURCE_DIR}/../../benchmark")

find_library(BENCHMARK_LIBRARY 
NAMES benchmark 
PATHS "${BENCHMARK_FOLDER}/build/src" 
REQUIRED
)


add_executable(test
test.cpp
math_c.cpp
)

add_executable(bench
bench.cpp
math_c.cpp
)

target_include_directories(bench
BEFORE PRIVATE "${BENCHMARK_FOLDER}/include"
)

target_link_libraries(bench
${BENCHMARK_LIBRARY}
pthread
)
