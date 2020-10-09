# Examples

project(hello_world_server)
cmake_minimum_required(VERSION 3.18)
set(CMAKE_BUILD_TYPE "Debug")

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
find_package(Boost 1.66.0 REQUIRED COMPONENTS system date_time filesystem thread)
if(Boost_FOUND)
    message(STATUS "Boost version: ${Boost_VERSION}")
    include_directories(${Boost_INCLUDE_DIRS})
endif()


set(WEBCC_LIBS webcc)
set(JSON_LIBS jsoncpp)
set(SIMPLE_HTTP_LIBS simple-web-server )
aux_source_directory(. CenterApp)

include_directories(third_party)
include_directories(${PROJECT_BINARY_DIR}/third_party)
include_directories(third_party/jsoncpp)
include_directories(third_party/simplehttp)

add_subdirectory(third_party/webcc)
add_subdirectory(third_party/jsoncpp)
add_subdirectory(third_party/simplehttp)
link_directories(/usr/lib64/mysql)


set(CENTER_LIBS ${WEBCC_LIBS} ${CMAKE_DL_LIBS} ${JSON_LIBS} ${SIMPLE_HTTP_LIBS} ${Boost_LIBRARIES})


add_executable(hello_world_server ${CenterApp})
target_link_libraries(hello_world_server ${CENTER_LIBS})
target_link_libraries(hello_world_server libmysqlclient.so)
target_include_directories(hello_world_server PRIVATE ${Boost_INCLUDE_DIR})
