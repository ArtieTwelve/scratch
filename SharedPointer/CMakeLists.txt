project(SharedPointer)
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD  17)
add_executable(SharedPointer main.cpp)

# must have this to link any lib used
target_link_libraries(SharedPointer libMediaAssets)