# Examples

project(hello_world_server)
cmake_minimum_required(VERSION 3.18)


set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
find_package(Boost 1.66.0 REQUIRED COMPONENTS system date_time filesystem)
if(Boost_FOUND)
    message(STATUS "Boost version: ${Boost_VERSION}")
    include_directories(${Boost_INCLUDE_DIRS})
endif()

include_directories(third_party)

include_directories(${PROJECT_BINARY_DIR}/third_party)

add_subdirectory(third_party/webcc)
set(EXAMPLE_LIBS webcc)

set(EXAMPLE_LIBS ${EXAMPLE_LIBS} ${CMAKE_DL_LIBS})
link_directories(/usr/lib64/mysql)

add_executable(hello_world_server main.cpp)
target_link_libraries(hello_world_server ${EXAMPLE_LIBS})
