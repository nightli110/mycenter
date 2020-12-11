set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SRCS
    MyCenter.hpp
    MyCenter.cpp
	)

add_library(center STATIC ${SRCS})