project(Threads)
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD  17)
add_executable(Thread_Basics Basics.cpp)
add_executable(Threads main.cpp)
add_executable(Threads_Mutex Mutex.cpp)
add_executable(Thread_Condition Condition.cpp)
add_executable(Thread_Future Future.cpp)

# must have this to link any lib used
#target_link_libraries(Threads libName)