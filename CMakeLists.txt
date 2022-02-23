cmake_minimum_required(VERSION 3.10.0)
project(preempt_sched)

set(CMAKE_C_FLAGS -D_XOPEN_SOURCE)

find_package(OpenSSL REQUIRED)
include_directories(include)
include_directories(${OPENSSL_INCLUDE_DIR})

add_executable(${CMAKE_PROJECT_NAME} src/main.c)
add_executable(ucontext src/ucontext.c)
target_link_libraries(${CMAKE_PROJECT_NAME} ${OPENSSL_CRYPTO_LIBRARY})


