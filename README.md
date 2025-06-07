
# Geometry2d

### A small C++ library for 2D geometry (points, lines, polygons, etc.).

## How to use

### Option 1: Add the library manually

1.  Clone this repo somewhere inside your project folder:
    ``` git clone [https://github.com/EmeraldDev52/2d-geometry.git](https://github.com/EmeraldDev52/2d-geometry.git)```
    
2.  In your project’s CMakeLists.txt, add:  
    ```add_subdirectory(path/to/2d-geometry)```
    
3.  Link the library to your target:  
    ```target_link_libraries(your_target PRIVATE geometry2d)```
    
4.  Include the headers in your code:  
    ```cpp
    #include <Geo2d/Point2d.h>
    ```
    
5. Build your project as usual with CMake.
    

----------

Option 2: Use FetchContent to add the library automatically

Add this to your project’s CMakeLists.txt instead of cloning:

```
include(FetchContent)

FetchContent_Declare(  
geometry2d  
GIT_REPOSITORY [https://github.com/EmeraldDev52/2d-geometry.git](https://github.com/EmeraldDev52/2d-geometry.git)  
GIT_TAG main  
)

FetchContent_MakeAvailable(geometry2d)

target_link_libraries(your_target PRIVATE geometry2d)
```
Then include the headers in your code as in Option 1.

----------
