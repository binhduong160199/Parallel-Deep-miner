#ifndef PARALLELDEEPMINER1_SECONDROBOT_H
#define PARALLELDEEPMINER1_SECONDROBOT_H
#include "robot.h"

class secondRobot: public Robot{
public:
    int mine(vector<vector<vector<int>>>& world, int x, int y) override;
    bool operator>(const secondRobot& rhs) const;  // overload > operator
private:
    int mineResult;  // Member variable to store the mine result

};


#endif //PARALLELDEEPMINER1_SECONDROBOT_H
