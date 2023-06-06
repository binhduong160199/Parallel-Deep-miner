#include "secondRobot.h"

int secondRobot::mine(vector<vector<vector<int>>> &world, int x, int y) {
    if (x < 0 || x >= world.size() || y < 0 || y >= world[x].size()) {
        throw std::out_of_range("Invalid coordinates");
    }
    vector<int>& col = world[x][y];
    sort(col.begin(), col.end(), greater<int>());
    return col[0] + col[1] + col[2];
}
bool secondRobot::operator>(const secondRobot& rhs) const {
    // Compare the mine result of the current robot with the mine result of rhs robot
    return mineResult > rhs.mineResult;
}