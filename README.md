# geometry2d

A small C++ library for 2D geometry (points, lines, etc.).

## How to use

### option 1

1.  Clone this repo somewhere in your project folder:  
    `git clone https://github.com/yourusername/geometry2d.git`
    
2.  In your project’s `CMakeLists.txt`, add:  
    `add_subdirectory(path/to/geometry2d)`
    
3.  Link the library to your target:  
    `target_link_libraries(your_target PRIVATE geometry2d)`
    
4.  Include the headers in your code:  
    `#include <geometry2d/Point2d.h>`
    
5.  Build your project as usual with CMake.
    

### Option2 : Use FetchContent to add the library automatically

Add this to your `CMakeLists.txt` instead of cloning:

```CMmake
include(FetchContent)
FetchContent_Declare(
  geometry2d
  GIT_REPOSITORY https://github.com/EmeraldDev52/2d-geometry.git
  GIT_TAG main
)
FetchContent_MakeAvailable(geometry2d)

