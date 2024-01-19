cmake_minimum_required(VERSION 3.12)
project(forg)

file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "include/*.h")
add_executable(forg ${SOURCES} ${HEADERS})
target_include_directories(forg PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)


