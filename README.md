# Geometry2d

A small, header‑only C++ static library for 2D geometry (vectors, lines, polygons, etc.).

---

## Requirements

* CMake ≥ 3.14 (for FetchContent)
* Git
* A C++17‑compatible compiler (GCC, Clang, MSVC)

---

## How to Use

Choose one of the following simple options.

### Option 1: Recommended – Pull via CPM.cmake

Add the snippet below to **your** `CMakeLists.txt`. CPM.cmake will clone, configure, and add Geometry2d automatically.

```cmake
cmake_minimum_required(VERSION 3.14)
project(my_project LANGUAGES CXX)


include(FetchContent)
FetchContent_Declare(
  CPM
  GIT_REPOSITORY https://github.com/cpm-cmake/CPM.cmake.git
  GIT_TAG        origin/main
)
FetchContent_MakeAvailable(CPM)

CPMAddPackage(
  NAME geometry2d
  GITHUB_REPOSITORY EmeraldDev52/2d-geometry
  GIT_TAG main
)

add_executable(my_app src/main.cpp)
target_link_libraries(my_app PRIVATE geometry2d)
```

Include headers in your code as:

```cpp
#include <Geo2d/Vector2d.h>
```

---

### Option 2: Add as a Subdirectory

Clone this repo and link it directly.

```bash
git clone https://github.com/EmeraldDev52/2d-geometry.git path/to/geometry2d
```

In **your** `CMakeLists.txt`:

```cmake
cmake_minimum_required(VERSION 3.10)
project(my_project LANGUAGES CXX)

add_subdirectory(path/to/geometry2d)

add_executable(my_app src/main.cpp)
target_link_libraries(my_app PRIVATE geometry2d)
```

Include headers as above.

---

### Option 3: Install & Find via `find_package`

1. **Build & install Geometry2d**:

   ```bash
   mkdir build && cd build
   cmake .. -DCMAKE_INSTALL_PREFIX=/your/install/path
   cmake --build .
   cmake --install .
   ```
2. **In your project**:

   ```cmake
   find_package(geometry2d CONFIG REQUIRED
                PATHS /your/install/path/lib/cmake/geometry2d)
   add_executable(my_app src/main.cpp)
   target_link_libraries(my_app PRIVATE geometry2d)
   ```

Include headers as above.

---

