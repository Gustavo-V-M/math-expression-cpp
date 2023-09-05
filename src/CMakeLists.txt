cmake_minimum_required(VERSION 3.27)
project(math-expression-parser)
set(EXECUTABLE_OUTPUT_PATH "~/Documents/projects/math-expression-parser/bin/")
add_executable(math-expression main.cpp CheckOrder.cpp Variable.cpp toPrefix.cpp)

