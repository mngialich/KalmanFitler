CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

if(APPLE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++ -std=c++1y")
ENDIF()

ADD_EXECUTABLE(Navigation
  Main.cpp
  KalmanFilter/KalmanFilter.cpp)