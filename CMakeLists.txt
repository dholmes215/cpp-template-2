cmake_minimum_required(VERSION 3.20.3)

project(hello VERSION 0.0.1
              DESCRIPTION "Application to print \"Hello World!\""
              HOMEPAGE_URL https://github.com/dholmes215/cpp-template-2
              LANGUAGES CXX)

# Targets can "link" this "library" to inherit the warnings specified in CompilerWarnings.cmake.
add_library(project_warnings INTERFACE)
include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

add_subdirectory(src)
