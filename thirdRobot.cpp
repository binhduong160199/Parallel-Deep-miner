#include "thirdRobot.h"

int thirdRobot::mine(vector<vector<vector<int>>> &world, int x, int y) {
    if (x < 0 || x >= world.size() || y < 0 || y >= world[0].size()) {
        throw std::out_of_range("Invalid coordinates");
    }
    vector<int>& col = world[x][y];
    int sum = 0;
    for (auto it = col.begin(); it != col.end(); it++) {
        sum += *it;
    }
    int size = col.size();
    if (size != 0) {
        return sum / size;
    } else {
        return 0; // Return 0 if the column is empty to avoid division by zero
    }
}


bool thirdRobot::operator==(const thirdRobot& rhs) const {
    return (this->posX == rhs.posX) && (this->posY == rhs.posY);
}

bool thirdRobot::operator!=(const thirdRobot& rhs) const {
    return !(*this == rhs);
}
