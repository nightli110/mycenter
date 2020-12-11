set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SRCS
    MyData.hpp
    MyData.cpp
    MyImage.hpp
    MyImage.cpp
    MyText.hpp
    MyText.cpp
	)

add_library(datatype STATIC ${SRCS})