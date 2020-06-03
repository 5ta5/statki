cmake_minimum_required(VERSION 3.10)
project(STATKI)

set(CMAKE_CXX_STANDARD 17)

file( GLOB SRC "source/*.cpp")

add_executable(statki source.cpp ${SRC})
target_link_libraries(statki PRIVATE -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio stdc++fs -pthread)
target_include_directories(statki PUBLIC include)
