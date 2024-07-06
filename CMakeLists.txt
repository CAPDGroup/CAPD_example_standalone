cmake_minimum_required(VERSION 3.13)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS YES)

add_subdirectory(src/CAPD)

function(build_example_executable_monofile EXAMPLE_EXECUTABLE_NAME)

  add_executable(${EXAMPLE_EXECUTABLE_NAME})
  target_link_libraries(${EXAMPLE_EXECUTABLE_NAME} capd)
  target_sources(${EXAMPLE_EXECUTABLE_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/${EXAMPLE_EXECUTABLE_NAME}.cpp)

endfunction()

add_subdirectory(src/capdAux)
add_subdirectory(src/capdAlg)
add_subdirectory(src/capdDynSys)
