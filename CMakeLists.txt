cmake_minimum_required(VERSION 3.16)
project(jvav_compiler)

add_definitions(-D_GLIBCXX_USE_CXX11_ABI=1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Include directories
include_directories(
    ${PROJECT_SOURCE_DIR}/third_party/antlr4-cpp-runtime/src
    ${PROJECT_SOURCE_DIR}/src/antlr
    ${PROJECT_SOURCE_DIR}/src/AST
    ${PROJECT_SOURCE_DIR}/src/Frontend
)

# Find pthread / threads
find_package(Threads REQUIRED)

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

set(src_dir
    ${PROJECT_SOURCE_DIR}/src/antlr/JvavLexer.cpp
    ${PROJECT_SOURCE_DIR}/src/antlr/JvavParser.cpp
    ${PROJECT_SOURCE_DIR}/src/antlr/JvavParserVisitor.cpp
    ${PROJECT_SOURCE_DIR}/src/antlr/JvavParserBaseVisitor.cpp
)

add_executable(jvav_compiler ${src_dir} src/main.cpp)

# Link antlr4 runtime and pthread
target_link_libraries(jvav_compiler PRIVATE antlr4-cpp-runtime Threads::Threads)
