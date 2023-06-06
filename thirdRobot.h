#ifndef PARALLELDEEPMINER1_THIRDROBOT_H
#define PARALLELDEEPMINER1_THIRDROBOT_H


#include "robot.h"

class thirdRobot : public Robot {
public:
    int mine(vector<vector<vector<int>>>& world, int x, int y) override;
    bool operator==(const thirdRobot& rhs) const;
    bool operator!=(const thirdRobot& rhs) const;
};

#endif //PARALLELDEEPMINER1_THIRDROBOT_H
