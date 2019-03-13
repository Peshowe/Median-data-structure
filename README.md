# Median Data Structure (Alcatraz task)

## Implementation

The data structure was implemented as a binary tree, the root always being the current median, the left subtree - a max heap and the right subtree - a min heap.

The code with the solution is located in **include/median_data_structure.h** and **src/median_data_structure.cpp**.  
A more in-depth explanation of the implementation and the reasoning behind it is given in the comments of those files.

## Build

To build using CMake:
```
 mkdir build && cd build
 cmake ../
 make

```

## Main
In **src** I've also included a **main.cpp** file that only has main() and can be used to play around with the data structure.  
To execute simply build and from the **build** directory run:
```
 ./main
```

## Unit tests

I wrote a few unit test cases, using the very lightweight [doctest C++ testing framework](https://github.com/onqtam/doctest).  
They are located in **tests/tests.cpp**.  

The test file is built with the rest of the project. To run it, from the **build** directory do:
```
 ./tests
```

The above instructions were succesfully executed on Ubuntu 18.04.
