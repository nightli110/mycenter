set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SRCS
    Myserver.hpp
    Myserver.cpp
	)

add_library(common STATIC ${SRCS})