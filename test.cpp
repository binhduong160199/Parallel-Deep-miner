#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "sortingRobot.h"
#include "secondRobot.h"
#include <stdexcept>
#include <iostream>
#include "thirdRobot.h"

TEST_CASE("Testing sortingRobot's mining operation") {
    std::cout << "\nTest for Sorting Robot:" << std::endl;
    sortingRobot robot;
    vector<vector<vector<int>>> world(5, vector<vector<int>>(5, vector<int>(10, 0)));

    SUBCASE("Normal mining operation") {
        int result = robot.mine(world, 1, 1);
        CHECK(result == 0);
        std::cout << "Mining operation successful" << std::endl;
    }
    SUBCASE("Exception for invalid coordinates") {
        CHECK_THROWS_AS(robot.mine(world, -1, -1), std::out_of_range);
        std::cout << "  Exception for invalid coordinates handled" << std::endl;
    }
}

TEST_CASE("Testing sortingRobot's operator overloading") {
    sortingRobot robot1;
    sortingRobot robot2;

    SUBCASE("Testing '==' operator") {
        robot1.move(1, 1);
        robot2.move(1, 1);
        CHECK(robot1 == robot2);
        std::cout << "'==' operator test passed" << std::endl;
    }
}

TEST_CASE("Testing secondRobot's mining operation") {
    std::cout << "\nTest for Second Robot:" << std::endl;
    secondRobot robot;
    vector<vector<vector<int>>> world(5, vector<vector<int>>(5, vector<int>(10, 0)));

    SUBCASE("Normal mining operation") {
        int result = robot.mine(world, 1, 1);
        CHECK(result == 0);
        std::cout << "Mining operation successful" << std::endl;
    }
    SUBCASE("Exception for out-of-bounds column index") {
        CHECK_THROWS_AS(robot.mine(world, 6, 2), std::out_of_range);
        std::cout << "  Exception for out-of-bounds column index handled" << std::endl;
    }
}

TEST_CASE("Testing secondRobot's operator overloading") {
    secondRobot robot1;
    secondRobot robot2;

    SUBCASE("Testing '>' operator") {
        robot1.move(1, 1);
        robot2.move(2, 2);

        if (robot1 > robot2) {
            std::cout << "robot1's mine result is greater than robot2's mine result" << std::endl;
        } else {
            std::cout << "robot2's mine result is greater than or equal to robot1's mine result" << std::endl;
        }
    }
}

TEST_CASE("Testing thirdRobot's mining operation") {
    std::cout << "\nTest for Third Robot:" << std::endl;
    thirdRobot robot;
    vector<vector<vector<int>>> world(3, vector<vector<int>>(3, vector<int>(3)));

    SUBCASE("Mining operation with non-zero result") {
        world[1][1][0] = 3;
        world[1][1][1] = 2;
        world[1][1][2] = 1;

        int result = robot.mine(world, 1, 1);
        CHECK(result == 2);
        std::cout << "  Mining operation successful" << std::endl;
    }
    SUBCASE("Exception for out-of-bounds row index") {
        CHECK_THROWS_AS(robot.mine(world, 2, 6), std::out_of_range);
        std::cout << "  Exception for out-of-bounds row index handled" << std::endl;
    }
}

TEST_CASE("Testing thirdRobot's operator overloading") {
    thirdRobot robot1;
    thirdRobot robot2;

    SUBCASE("Testing '==' operator") {
        robot1.move(1, 1);
        robot2.move(1, 1);
        CHECK(robot1 == robot2);
        std::cout << "'==' operator test passed" << std::endl;
    }

    SUBCASE("Testing '!=' operator") {
        robot1.move(1, 1);
        robot2.move(2, 2);
        CHECK(robot1 != robot2);
        std::cout << "'!=' operator test passed" << std::endl;
    }
}
