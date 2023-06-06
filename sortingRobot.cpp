#include "sortingRobot.h"
#include <algorithm>
#include <functional>
#include <vector>

int sortingRobot::mine(vector<vector<vector<int>>> &world, int x, int y) {
    if (x < 0 || x >= world.size() || y < 0 || y >= world[x].size()) {
        throw std::out_of_range("Invalid coordinates");
    }

    vector<int>& col = world[x][y];
    sort(col.begin(), col.end(), greater<int>());
    return col[0];
}

bool sortingRobot::operator==(const sortingRobot& rhs) const {
    // Let's compare positions of robots for equality
    return (this->posX == rhs.posX) && (this->posY == rhs.posY);
}