cmake_minimum_required(VERSION 3.12)
project(worleynoise)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

find_package(Stb REQUIRED)

add_executable(worleynoisegen)

file(GLOB_RECURSE PUB_SRCS CONFIGURE_DEPENDS include/*.h *.hpp)
file(GLOB_RECURSE PRIV_SRCS CONFIGURE_DEPENDS src/*.c *.cpp)

target_include_directories(worleynoisegen
  PUBLIC
    include
    ${Stb_INCLUDE_DIR}
)

target_sources(worleynoisegen
  PRIVATE
    src/main.cpp
    src/worleygen.cpp
)

target_link_libraries(worleynoisegen
  INTERFACE
    Stb
)
