## Geometry2d

A small C++ library for 2D geometry (vectors, lines, polygons, and more).

---

### Requirements

* CMake ≥ 3.14 (for CPM.cmake support)
* A C++17‑compatible compiler (GCC, Clang, MSVC)

---

## Installation Options

Choose the method that best fits your workflow.

### 1. HEAVILY RECOMMENDED – Direct CPM.cmake Download

Automatically download and use CPM.cmake at configure time.


example CMakeLists.txt
```cmake
cmake_minimum_required(VERSION 3.14)
project(my_project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1 Download CPM.cmake into build dir
file(DOWNLOAD
  https://github.com/cpm-cmake/CPM.cmake/releases/latest/download/CPM.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake
)

# 2 Include and initialize CPM
include(${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake)

# 3 Fetch Geometry2d
CPMAddPackage(
  NAME        geometry2d
  GITHUB_REPOSITORY EmeraldDev52/2d-geometry
  GIT_TAG     main
  OPTIONS     "BUILD_TESTS OFF"
)

# 4 Link to your executable
add_executable(my_app src/main.cpp)
target_link_libraries(my_app PRIVATE Geo2d::geometry2d)
```

Include in code:

```cpp
#include <Geo2d/Vector2d.h>
```

---

### 2. Add as a Subdirectory

Clone into your project and use CMake’s `add_subdirectory`.

```bash
git clone https://github.com/EmeraldDev52/2d-geometry.git path/to/geometry2d
```

In your `CMakeLists.txt`:

```cmake
cmake_minimum_required(VERSION 3.10)
project(my_project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Pull in the library
add_subdirectory(path/to/geometry2d)

# Link your target
add_executable(my_app src/main.cpp)
# `geometry2d` exports the `Geo2d::geometry2d` target
target_link_libraries(my_app PRIVATE Geo2d::geometry2d)
```

Include in code:

```cpp
#include <Geo2d/Vector2d.h>
```

---

### 3. Install & Find via `find_package`

1. **Build & install Geometry2d**:

   ```bash
   mkdir build && cd build
   cmake .. -DCMAKE_INSTALL_PREFIX=/your/install/path
   cmake --build .
   cmake --install .
   ```
2. **In your project**:

   ```cmake
   cmake_minimum_required(VERSION 3.10)
   project(my_project LANGUAGES CXX)

   set(CMAKE_CXX_STANDARD 17)
   set(CMAKE_CXX_STANDARD_REQUIRED ON)

   find_package(geometry2d CONFIG REQUIRED
                PATHS /your/install/path/lib/cmake/geometry2d)

   add_executable(my_app src/main.cpp)
   target_link_libraries(my_app PRIVATE Geo2d::geometry2d)
   ```

Include in code:

```cpp
#include <Geo2d/Vector2d.h>
```

---

## Example Usage

```cpp
#include <iostream>
#include <Geo2d/Vector2d.h>

int main() {
    Geo2d::Vector2d v1{3.0, 4.0};
    Geo2d::Vector2d v2{1.0, 2.0};

    std::cout << v1+v2.magnitute() << std::endl;

    return 0;
}
```

Compile and run:

```bash
mkdir build && cd build
cmake ..
cmake --build .
./my_app
```

---

## ⚙️ Configuration Options

| Option           | Default | Description                    |
| ---------------- | ------- | ------------------------------ |
| `BUILD_TESTS`    | ON      | Build the library’s unit tests |
| `BUILD_EXAMPLES` | OFF     | Build example executables      |

Disable tests:

```bash
cmake .. -DBUILD_TESTS=OFF
```

---

## 📞 Support & Contributing

Found a bug or want to contribute? Please open an issue or pull request on the [GitHub repository](https://github.com/EmeraldDev52/2d-geometry).

---

*Last updated: June 8, 2025*
