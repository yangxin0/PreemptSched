cmake_minimum_required(VERSION 3.10.0)
project(PreemptiveSchedulingDemo)

aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC)

add_executable(${CMAKE_PROJECT_NAME} ${SRC})

