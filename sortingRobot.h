#ifndef PARALLELDEEPMINER1_SORTINGROBOT_H
#define PARALLELDEEPMINER1_SORTINGROBOT_H
#include "robot.h"
#include "world.h"

class sortingRobot: public Robot {
public:
    int mine(vector<vector<vector<int>>>& world, int x, int y) override;
    bool operator==(const sortingRobot& rhs) const;  // define == operator
};


#endif //PARALLELDEEPMINER1_SORTINGROBOT_H