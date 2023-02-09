add_library(hello greeting.cpp greeting.hpp)
target_include_directories(hello INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(
  hello
  PUBLIC project_options fmt::fmt
  PRIVATE project_warnings)

option(PROJECT_OUTPUT_HTML "Generate a .html file for WASM/Emscripten builds" OFF)
if (PROJECT_OUTPUT_HTML)
  set(CMAKE_EXECUTABLE_SUFFIX ".html")
endif()

add_executable(hello_app main.cpp)
target_link_libraries(hello_app PRIVATE project_options project_warnings hello)

install(TARGETS hello_app RUNTIME DESTINATION bin)
if (PROJECT_OUTPUT_HTML)
  install(FILES "$<TARGET_FILE_DIR:hello_app>/hello_app.wasm" "$<TARGET_FILE_DIR:hello_app>/hello_app.js" DESTINATION bin)
endif()
