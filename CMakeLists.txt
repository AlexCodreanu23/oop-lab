cmake_minimum_required(VERSION 3.24)
project(POO_2_1)

set(CMAKE_CXX_STANDARD 17)

add_executable(POO_2_1 main.cpp Fictional.cpp Fictional.h Book.h Book.cpp NonFiction.cpp NonFiction.h NoTitleException.h InvalidCodeException.h InvalidCodeException.cpp)
