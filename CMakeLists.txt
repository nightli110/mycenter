# Examples

project(hello_world_server)
cmake_minimum_required(VERSION 3.5)
set(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_CXX_FLAGS "-std=c++0x")

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
find_package(Boost REQUIRED COMPONENTS system date_time filesystem thread)
find_package (glog 0.4.0 REQUIRED)

if(Boost_FOUND)
    message(STATUS "Boost version: ${Boost_VERSION}")
    include_directories(${Boost_INCLUDE_DIRS})
endif()

set(JSON_LIBS jsoncpp)
set(SIMPLE_HTTP_LIBS simple-web-server )
set(Mycenter)

####model
set(BASECENTER center)
set(APP App)
set(COMMON MyCommon)
set(DATATYPE datatype)
set(DB DB)
set(SERVER server)


aux_source_directory(. CenterApp)

include_directories(${PROJECT_BINARY_DIR}/3rdparty)
include_directories(3rdparty/jsoncpp)
include_directories(3rdparty/simplehttp)


add_subdirectory(3rdparty/jsoncpp)
add_subdirectory(3rdparty/simplehttp)

add_subdirectory(mycenter)

set(CENTER_LIBS ${CMAKE_DL_LIBS} ${JSON_LIBS} ${SIMPLE_HTTP_LIBS} ${Boost_LIBRARIES} ${Mycenter_LIBS})

set(MODEL_LIBS MyCommon App BaseCenter datatype DB server)


add_executable(hello_world_server ${CenterApp})
target_link_libraries(hello_world_server ${MODEL_LIBS})
target_link_libraries(hello_world_server ${CENTER_LIBS})
target_link_libraries(hello_world_server glog::glog)

target_link_libraries(hello_world_server libmysqlclient.so)
target_include_directories(hello_world_server PRIVATE ${Boost_INCLUDE_DIR})
