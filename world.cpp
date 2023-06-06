#include "world.h"
#include <ctime>
#include "fourthRobot.h"
#include <iostream>
using namespace std;

World::World() {
    //a 3d world 5x5x10
    world.resize(5);             // resize first dimension to 5
    for (int i = 0; i < 5; ++i) {
        world[i].resize(5);      // resize second dimension to 5 for each element in the first dimension
        for (int j = 0; j < 5; ++j) {
            world[i][j].resize(10);  // resize third dimension to 10 for each element in the second dimension
        }
    }
    std::srand(std::time(0)); //generate random number
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            for (int z = 0; z < 10; z++) {
                world[x][y][z] = 1 + std::rand() % 9;
            }
        }
    }
}

