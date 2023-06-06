#ifndef PARALLELDEEPMINER1_PLAY_H
#define PARALLELDEEPMINER1_PLAY_H
#include <vector>
#include "world.h"


class Play {

public:
    Play();
    void showWorld(int posX, int posY);
    void startGame();
    void countPoint(int minePoints, int& playerPoints);

private:
    World world;

};


#endif //PARALLELDEEPMINER1_PLAY_H
