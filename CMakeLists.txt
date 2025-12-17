cmake_minimum_required(VERSION 3.10)
project(Blackjack)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED_ON)

add_executable(Blackjack
	main.cpp
	game.cpp
	player.cpp
)

#for getting raylib
find_package(raylib REQUIRED)
target_link_libraries(Blackjack PRIVATE raylib)
