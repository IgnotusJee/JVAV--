cmake_minimum_required(VERSION 3.16)
project(jvav_compiler)

add_definitions(-D_GLIBCXX_USE_CXX11_ABI=1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include directories
include_directories(
    ${PROJECT_SOURCE_DIR}/third_party/antlr4-cpp-runtime/src
    ${PROJECT_SOURCE_DIR}/src/
    ${PROJECT_SOURCE_DIR}/src/antlr
    /usr/lib/llvm-18/include/
)

# Find pthread / threads
find_package(Threads REQUIRED)
find_package(LLVM REQUIRED)

# ANTLR4 runtime sources
file(GLOB antlr4-cpp-src
    ${PROJECT_SOURCE_DIR}/third_party/antlr4-cpp-runtime/src/*.cpp
    ${PROJECT_SOURCE_DIR}/third_party/antlr4-cpp-runtime/src/atn/*.cpp
    ${PROJECT_SOURCE_DIR}/third_party/antlr4-cpp-runtime/src/dfa/*.cpp
    ${PROJECT_SOURCE_DIR}/third_party/antlr4-cpp-runtime/src/misc/*.cpp
    ${PROJECT_SOURCE_DIR}/third_party/antlr4-cpp-runtime/src/support/*.cpp
    ${PROJECT_SOURCE_DIR}/third_party/antlr4-cpp-runtime/src/tree/*.cpp
    ${PROJECT_SOURCE_DIR}/third_party/antlr4-cpp-runtime/src/tree/pattern/*.cpp
    ${PROJECT_SOURCE_DIR}/third_party/antlr4-cpp-runtime/src/tree/xpath/*.cpp
    ${PROJECT_SOURCE_DIR}/third_party/antlr4-cpp-runtime/src/internal/*.cpp
)

add_library(antlr4-cpp-runtime ${antlr4-cpp-src})
target_link_libraries(antlr4-cpp-runtime PUBLIC Threads::Threads)

file(GLOB_RECURSE SRC_FILES
    src/*.cpp
    src/*/*.cpp
    src/*/*/*.cpp
    src/*/*.hpp
    src/*/*/*.hpp
)

add_executable(jvav_compiler ${SRC_FILES}
        src/Frontend/IRGenerator.hpp
        src/Frontend/SymbolTable.hpp)

# Link antlr4 runtime and pthread
target_link_libraries(jvav_compiler PRIVATE antlr4-cpp-runtime Threads::Threads LLVM)
