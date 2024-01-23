cmake_minimum_required(VERSION 3.10)
project(capd_example)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS YES)

add_executable(${PROJECT_NAME} src/main.cpp)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)

add_dependencies(${PROJECT_NAME} capd)

add_subdirectory(src/CAPD)
target_link_libraries(${PROJECT_NAME} PRIVATE capd)
