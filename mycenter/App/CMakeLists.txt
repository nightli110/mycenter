set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SRCS
    InferenceAPP.hpp
    InferenceAPP.cpp
    MyAPPAction.hpp
    MyAPPAction.cpp
	)

add_library(App SHARED  ${SRCS})