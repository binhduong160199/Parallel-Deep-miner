#ifndef PARALLELDEEPMINER1_WORLD_H
#define PARALLELDEEPMINER1_WORLD_H
#include <vector>
#include <iostream>
using namespace std;


class World {
public:
    World();
    //using vector to create a 3d world
    vector<vector<vector<int>>> world;

};


#endif //PARALLELDEEPMINER1_WORLD_H
