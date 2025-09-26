## **How to Install GoogleTest on Windows: A Brief Tutorial**

This guide walks you through installing GoogleTest (gtest) on a Windows system, focusing on using MinGW (specifically WinLibs). We cover building, installing, and configuring GoogleTest for easy use in C++ projects.

### **Step 1: Prerequisites**

1. **CMake**: Download and install [CMake](https://cmake.org/download/), and ensure it is added to your system PATH.
2. **MinGW (WinLibs)**: Download [WinLibs MinGW](https://winlibs.com/), and extract it to a directory like `C:\tools\winlibs-mingw64`.
3. **Add MinGW to PATH**: Add `C:\tools\winlibs-mingw64\bin` to your system PATH.

### **Step 2: Clone GoogleTest**

Open a command prompt and run:

```sh
git clone https://github.com/google/googletest.git
cd googletest
```

### **Step 3: Build GoogleTest**

1. **Create a Build Directory**:
   ```sh
   mkdir build
   cd build
   ```

2. **Configure the Build with CMake**:
   ```sh
   cmake -G "MinGW Makefiles" -DCMAKE_CXX_STANDARD=17 -DCMAKE_CXX_COMPILER=g++ -DCMAKE_C_COMPILER=gcc ..
   ```

3. **Compile the GoogleTest Library**:
   ```sh
   mingw32-make
   ```

### **Step 4: Install GoogleTest**

There are two different methods for installing GoogleTest: **manual installation** by copying the files or using **make install** with a custom path. Choose whichever method suits your workflow.

#### **Method 1: Manual Installation**

1. **Locate the Build Artifacts**:
   - After running `mingw32-make`, the static library files (`libgtest.a`, `libgtest_main.a`, `libgmock.a`, `libgmock_main.a`) will be present in the `build` directory.

2. **Copy Library Files**:
   - Copy the `.a` files to the `lib` folder of your MinGW installation:
     - Copy `libgtest.a`, `libgtest_main.a`, `libgmock.a`, and `libgmock_main.a` to `C:\tools\winlibs-mingw64\lib`.

3. **Copy Include Files**:
   - Copy the GoogleTest header files to the `include` folder of MinGW:
     - Navigate to `googletest/include` and `googlemock/include`.
     - Copy both `gtest` and `gmock` folders into `C:\tools\winlibs-mingw64\include`.

**CMakeLists.txt for Manual Installation**:

```cmake
cmake_minimum_required(VERSION 3.10)

# Project Name
project(SimpleGTestProject)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(include ${CMAKE_SOURCE_DIR}/include)

# Add the calc library
add_library(calc src/calc.cpp)

# Add executable for unit tests
add_executable(test_calc test/test_calc.cpp)

# Link the test executable with GoogleTest and the calc library
target_link_libraries(test_calc gtest gtest_main calc pthread)

# Enable testing
enable_testing()
add_test(NAME CalcTests COMMAND test_calc)
```

In this setup, GoogleTest headers and libraries are assumed to be available in MinGW's `include` and `lib` directories, respectively. Therefore, you don't need to explicitly specify paths for GoogleTest, as MinGW should find them automatically.

#### **Method 2: Using `make install` with Custom Path**

1. **Specify a Custom Installation Directory**:
   - Run CMake again, this time specifying an installation prefix to avoid system-protected locations:

   ```sh
   cmake -G "MinGW Makefiles" -DCMAKE_INSTALL_PREFIX="C:/my_gtest_install" ..
   ```

2. **Run Install Command**:
   - Install GoogleTest to your custom path:

   ```sh
   mingw32-make install
   ```

   This will install GoogleTest to `C:/my_gtest_install`, with header files under `include/` and library files under `lib/`.

**CMakeLists.txt for Installation via `make install`**:

```cmake
cmake_minimum_required(VERSION 3.10)

# Project Name
project(SimpleGTestProject)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)

# Find GoogleTest (use the custom installation path)
find_package(GTest REQUIRED PATHS "C:/my_gtest_install")

# Include directories
include_directories(${GTEST_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/include)

# Add the calc library
add_library(calc src/calc.cpp)

# Add executable for unit tests
add_executable(test_calc test/test_calc.cpp)

# Link the test executable with GoogleTest and the calc library
target_link_libraries(test_calc ${GTEST_LIBRARIES} calc pthread)

# Enable testing
enable_testing()
add_test(NAME CalcTests COMMAND test_calc)
```

In this `CMakeLists.txt`, the GoogleTest installation path (`C:/my_gtest_install`) is explicitly specified using the `find_package()` command. This allows CMake to locate the installed files.

### **Summary of Installation Methods**

- **Method 1 (Manual Installation)**: 
  - **Copy the compiled library files** (`*.a` files) to `C:\tools\winlibs-mingw64\lib`.
  - **Copy the include files** (`gtest` and `gmock` folders) to `C:\tools\winlibs-mingw64\include`.
  - **CMake Configuration**: No need for an explicit installation path in CMake.

- **Method 2 (CMake Install Command)**:
  - Specify a custom installation directory with `-DCMAKE_INSTALL_PREFIX`.
  - Run `mingw32-make install` to install GoogleTest.
  - **CMake Configuration**: Use `find_package()` to locate the installed GoogleTest library.

### **Summary Commands**

1. **Clone GoogleTest**:
   ```sh
   git clone https://github.com/google/googletest.git
   cd googletest
   mkdir build
   cd build
   ```

2. **Configure, Build, and Install**:
   ```sh
   cmake -G "MinGW Makefiles" -DCMAKE_CXX_STANDARD=17 -DCMAKE_CXX_COMPILER=g++ -DCMAKE_C_COMPILER=gcc ..
   mingw32-make
   ```
   
3. **Choose an Installation Method**:
   - **Manual Installation**: Copy files to MinGW's `lib` and `include` directories.
   - **Using `make install`**:
     ```sh
     cmake -G "MinGW Makefiles" -DCMAKE_INSTALL_PREFIX="C:/my_gtest_install" ..
     mingw32-make install
     ```

4. **Configure Your Project to Use GoogleTest**:
   - For **Manual Installation**, use `CMakeLists.txt` without specifying paths.
   - For **make install**, use `find_package(GTest REQUIRED PATHS "C:/my_gtest_install")` in `CMakeLists.txt`.
