cmake_minimum_required(VERSION 3.23)
project(paralleldeepminer1)

set(CMAKE_CXX_STANDARD 14)

add_executable(paralleldeepminer1 main.cpp world.cpp world.h play.cpp play.h robot.cpp robot.h sortingRobot.cpp sortingRobot.h secondRobot.cpp secondRobot.h thirdRobot.cpp thirdRobot.h fourthRobot.cpp fourthRobot.h)
