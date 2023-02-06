cmake_minimum_required(VERSION 3.20.3)

option(PROJECT_USE_VCPKG "Use vcpkg for library dependencies" ON)
option(PROJECT_GIT_SUBMODULE "Update submodules during build" OFF)
if(PROJECT_USE_VCPKG)
  # Optionally update vcpkg submodule (mainly for use by CI)
  include(cmake/UpdateSubmodule.cmake)
  update_submodule("${CMAKE_CURRENT_LIST_DIR}/vcpkg")

  # Configure vcpkg
  include(cmake/ConfigureVcpkg.cmake)
  configure_vcpkg("${CMAKE_CURRENT_LIST_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake")
endif()
set(CMAKE_SYSTEM_PROCESSOR x86)

project(
  hello
  VERSION 0.0.1
  DESCRIPTION "Application to print \"Hello World!\""
  HOMEPAGE_URL https://github.com/dholmes215/cpp-template-2
  LANGUAGES CXX)

# Find dependencies.
if(BUILD_TESTING)
  find_package(Catch2 REQUIRED)
endif()
find_package(fmt REQUIRED)

# Targets can "link" this "library" to inherit project options.
add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_20) # Require _at least_ C++20.

# Targets can "link" this "library" to inherit the warnings specified in CompilerWarnings.cmake.
add_library(project_warnings INTERFACE)
include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

# Allow for static analysis options.
include(cmake/StaticAnalyzers.cmake)

option(PROJECT_OUTPUT_HTML "Generate a .html file for WASM/Emscripten builds" OFF)
if (PROJECT_OUTPUT_HTML)
  set(CMAKE_EXECUTABLE_SUFFIX ".html")
endif()

add_subdirectory(src)

if(BUILD_TESTING)
  include(CTest)
  include(Catch)
  add_subdirectory(tests)
endif()
