project(hello)
cmake_minimum_required(VERSION 3.5)
set(JSON_LIBS jsoncpp)

find_package(CURL REQUIRED)
include_directories(jsoncpp)
add_subdirectory(jsoncpp)
include_directories(${CURL_INCLUDE_DIR})

add_executable(hello test2.cpp)
target_link_libraries(hello ${JSON_LIBS})
target_link_libraries(hello ${CURL_LIBRARIES})