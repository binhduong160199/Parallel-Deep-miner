#include "sortingRobot.h"
#include <algorithm>
#include <functional>
#include <vector>

#include "fourthRobot.h"
void fourthRobot::clean(vector<vector<vector<int>>> &world, int x, int y) {
    vector<int>& col = world[x][y];

    // Sort the column in ascending order
    sort(col.begin(), col.end(), less<int>());
}