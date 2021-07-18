add_executable(hello main.cpp)
target_compile_features(hello PUBLIC cxx_std_20)  # Require _at least_ C++20 for this and dependents
set_target_properties(hello PROPERTIES CXX_STANDARD 20  # Use _exactly_ C++20 for this
                                       CXX_STANDARD_REQUIRED ON
                                       CXX_EXTENSIONS OFF)
target_link_libraries(hello PRIVATE project_warnings)
