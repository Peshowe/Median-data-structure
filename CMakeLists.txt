cmake_minimum_required (VERSION 2.6)
project (MedianStruct)

# Include the header
include_directories(include)

# Set variable to point to the source files
set(SOURCES src/main.cpp src/median_data_structure.cpp)


add_executable(main ${SOURCES})
