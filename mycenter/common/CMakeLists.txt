set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(test
    Common.hpp
    Common.cpp
	)

add_library(MyCommon STATIC ${test})