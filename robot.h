#ifndef PARALLELDEEPMINER1_ROBOT_H
#define PARALLELDEEPMINER1_ROBOT_H

#include <vector>
using namespace  std;

class Robot {
public:
    // use reference for vector because we want any changes inside the function
    // will affect the vector
    virtual int mine(vector<vector<vector<int>>>& world, int x, int y) = 0;
    void move(int x, int y);

protected:
    int posX, posY;
};


#endif //PARALLELDEEPMINER1_ROBOT_H
