set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SRCS
    messagequeue.hpp
    messagequeue.cpp
	)

add_library(DB STATIC ${SRCS})