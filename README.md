# NOTE: THIS IS MY FIRST TIME USING A BUILD SYSTEM SO IT MAY NOT WORK AS THE INSTRUCTIONS SAY
# Geometry2d

### A small C++ static library for 2D geometry (vectors, lines, polygons, etc).

----------

## How to Use

### Option 1: Add as a subdirectory (recommended for CMake projects)

#### Step 1: Clone the repo inside your project folder (or anywhere you want): 
```bash 
git clone https://github.com/EmeraldDev52/2d-geometry.git
```
#### Step 2: In your project's CMakeLists.txt, add:  
```cmake
add_subdirectory(path/to/2d-geometry) 
```
```cmake 
target_link_libraries(your_target PRIVATE geometry2d)
# Replace 'your_target' below with the actual target name of your executable or library
```
sample cmake and main.cpp
```cmake
cmake_minimum_required(VERSION 3.14)
project(MyApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(2d-geometry)

add_executable(myapp main.cpp)

target_link_libraries(myapp PRIVATE geometry2d)
```
```cpp
#include "Geo/Vector2d.h"
#include <iostream>

int main(){
    Vector2d v1(5, 3);
    Vector2d v2(4.3, 2.43);
    std::cout << v1.distance(v2) << std::endl;
}
```


#### Step 3: Include headers in your source files like:  
```cpp
#include <Geo2d/Vector2d.h>
```
----------

### Option 2: Install and use with find_package

#### Step 1: Build and install the library:  
```bash
mkdir build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/your/install/path
cmake --build .
cmake --install .
```
#### Step 2: In your own project, find and link the library: 
```cmake 
find_package(geometry2d REQUIRED PATHS /path/to/install)  
target_link_libraries(your_target PRIVATE Geo2d::geometry2d)
```
#### Step 3: Include headers as usual:  
```cpp
#include <Geo2d/Vector2d.h>
```
----------

### Option 3: Use in non-CMake projects (after building with CMake)

#### Step 1: Build the library with CMake:  
```bash
mkdir build  
cd build  
cmake .. -DCMAKE_BUILD_TYPE=Release  
cmake --build .
```

This will create a static library:  
On Linux/macOS: build/libgeometry2d.a  
On Windows: build/geometry2d.lib

#### Step 2: Compile your project using any compiler and link to the library

For g++ or clang++:  
g++ -std=c++17 -I/path/to/geometry2d/include main.cpp -L/path/to/geometry2d/build -lgeometry2d

For MSVC (Windows):  
cl /std:c++17 /I path\to\geometry2d\include main.cpp path\to\geometry2d\build\geometry2d.lib

#### Step 3: Include headers like this in your code:  
```cpp
#include <Geo2d/Vector2d.h>
```
Make sure you use the correct include path and link against the built library file.

----------

## Requirements

-   CMake 3.10 or higher
    
-   C++17 compatible compiler
    

----------
