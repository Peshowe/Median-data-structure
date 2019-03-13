cmake_minimum_required (VERSION 2.6)
project (MedianStruct)

# For the unit tests
enable_testing()

# Include the header
include_directories(include)

# Set variable to point to the source files
set(SOURCES src/main.cpp src/median_data_structure.cpp)

add_executable(main ${SOURCES})



# Prepare doctest for other targets to use
add_library(doctest INTERFACE)
target_include_directories(doctest INTERFACE path/to/doctest)

set(TESTS tests/tests.cpp src/median_data_structure.cpp)

# Make test executable
add_executable(tests ${TESTS})
target_link_libraries(tests doctest)
