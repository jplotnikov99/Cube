cmake_minimum_required(VERSION 3.22)

project(
 DifSolver
 VERSION 0.01
 LANGUAGES C CXX)

add_compile_options(-O3)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})


add_subdirectory(draw_module)
add_subdirectory(solve_module)

set(include_dir ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_include_directories(draw_module PRIVATE ${include_dir})
target_include_directories(solve_module PRIVATE ${include_dir})

add_executable(main main.cpp)

target_include_directories(main PRIVATE ${include_dir})

target_link_libraries(main PRIVATE draw_module solve_module ${CURSES_LIBRARIES})