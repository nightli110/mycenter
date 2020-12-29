project(hello)
cmake_minimum_required(VERSION 3.5)
set(JSON_LIBS jsoncpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

find_package(CURL REQUIRED Threads)
find_package (glog 0.4.0 REQUIRED)
include_directories(${PROJECT_BINARY_DIR}/3rdparty)

MESSAGE( STATUS "${PROJECT_BINARY_DIR}/3rdparty")
include_directories(3rdparty/jsoncpp)
add_subdirectory(3rdparty/jsoncpp)
include_directories(${CURL_INCLUDE_DIR})

add_executable(hello testthreadpool.cpp)
target_link_libraries(hello ${JSON_LIBS})
target_link_libraries(hello ${CURL_LIBRARIES})

target_link_libraries(hello ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(hello glog::glog)
