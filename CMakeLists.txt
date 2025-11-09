cmake_minimum_required(VERSION 3.16)
project(dsa LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Compiler warnings
add_compile_options(-Wall -Wextra -Werror -pedantic -g)

# Include headers
include_directories(include)

# Source and test files
file(GLOB SRC_FILES src/*.cpp)
file(GLOB TEST_FILES test/*.cpp)

# Executable target
add_executable(test_dynamic_array ${TEST_FILES})
