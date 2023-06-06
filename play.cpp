#include "play.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include "robot.h"
#include "sortingRobot.h"
#include "secondRobot.h"
#include "thirdRobot.h"
#include "fourthRobot.h"

using namespace std;
mutex m;

Play::Play() {

}

void Play::showWorld(int posX, int posY) {
    for (int z = 9; z >= 0; z--) {
        cout << "z=" << z << endl;
        for (int y = 0; y < 5; y++) {
            for (int x = 0; x < 5; x++) {
                if (z == 9 && x == posX && y == posY) {
                    cout << "🤖";
                } else {
                    cout << world.world[x][y][z] << " ";
                }
            }
            cout << " " << endl;
        }

    }
}

void Play::countPoint(int minePoints, int& playerPoints) {
    m.lock();
    playerPoints += minePoints;
    m.unlock();
}

void Play::startGame() {
    int number;
    cout << "Choose your Robot 1: Sorting Robot, 2: Top Three Robot, 3: Average Robot " << endl;
    cout << "- Sorting Robot will sort the number in the descending order and takes the first element as Point" << endl;
    cout << "- Second Robot will calculate the average of the elements" << endl;
    cout << "- Third Robot will add three first elements" << endl;
    cin >> number;
    // using smart point we don't have to delete them after that

    shared_ptr<Robot> robot1;
    shared_ptr<Robot> robot2;
    shared_ptr<Robot> robot3;
    shared_ptr<Robot> robot4;
    shared_ptr<Robot> robot5;
    if(number == 1){
        robot1 = make_shared<sortingRobot>();
        robot2 = make_shared<sortingRobot>();
        robot3 = make_shared<sortingRobot>();
        robot4 = make_shared<sortingRobot>();
        robot5 = make_shared<sortingRobot>();
    }else if(number == 2){
        robot1 = make_shared<secondRobot>();
        robot2 = make_shared<secondRobot>();
        robot3 = make_shared<secondRobot>();
        robot4 = make_shared<secondRobot>();
        robot5 = make_shared<secondRobot>();
    } else if(number == 3){
        robot1 = make_shared<thirdRobot>();
        robot2 = make_shared<thirdRobot>();
        robot3 = make_shared<thirdRobot>();
        robot4 = make_shared<thirdRobot>();
        robot5 = make_shared<thirdRobot>();
    }

    // 5 rounds for one game
    int round = 1;
    int playerPoints = 0;

    int x = 0, y = 0;
    auto startTime = std::chrono::steady_clock::now();
    while (round <= 5) {
        cout << "Round " << round << endl;
        showWorld(x, y);

        char move;
        cout << "Move w (up), s(down), a (left), d (right): " << endl;
        cin >> move;

        // change move
        switch (move) {
            case 'w':
                if (y > 0) {
                    y--;
                }
                break;
            case 's':
                if (y <= 0) {
                    y++;
                }
                break;
            case 'a':
                if (x > 0) {
                    x--;
                }
                break;
            case 'd':
                if (x <= 4) {
                    x++;
                }
                break;
            default:
                cout << "Invalid move" << endl;

        }

        robot1->move(x, y);
        robot2->move(x, y);
        robot3->move(x, y);
        robot4->move(x, y);
        robot5->move(x, y);

        cout << "Position (" << x << ": " << y << ")" << endl;

        // Run the mine function for each robot in a separate thread
    //        int playerPoints1, playerPoints2, playerPoints3, playerPoints4, playerPoints5;
    //        thread t1(&Play::countPoint, this, robot1->mine(world.world, x, y), playerPoints1);
    //        thread t2(&Play::countPoint, this, robot1->mine(world.world, x, y), playerPoints2);
    //        thread t3(&Play::countPoint, this, robot1->mine(world.world, x, y), playerPoints3);
    //        thread t4(&Play::countPoint, this, robot1->mine(world.world, x, y), playerPoints4);
    //        thread t5(&Play::countPoint, this, robot1->mine(world.world, x, y), playerPoints5);

        // lambda expression
        // the reason for using lambda is we don't want to write it on the header
        // using & (reference) to save the value of the for example point after
        // the lambda function executed
        thread t1([&]() { //capture all variables by reference ([&]).
            int points = robot1->mine(world.world, x, y);
            m.lock();
            playerPoints += points;
            m.unlock();
        });
        thread t2([&]() {
            int points = robot2->mine(world.world, x, y);
            m.lock();
            playerPoints += points;
            m.unlock();
        });
        thread t3([&]() {
            int points = robot3->mine(world.world, x, y);
            m.lock();
            playerPoints += points;
            m.unlock();
        });
        thread t4([&]() {
            int points = robot4->mine(world.world, x, y);
            m.lock();
            playerPoints += points;
            m.unlock();
        });
        thread t5([&]() {
            int points = robot5->mine(world.world, x, y);
            m.lock();
            playerPoints += points;
            m.unlock();
        });

        // join everything together
        t1.join();
        t2.join();
        t3.join();
        t4.join();
        t5.join();
        cout << "The point you got 5 times " << robot1->mine(world.world, x, y) << endl;
        cout << "Your points:  " << playerPoints << endl;
        round++;

        //stufe 2 from the fourth exercise
        //change world game
        //z indexes will be sorted in asc order.
        if (playerPoints % 50 == 0) {
            shared_ptr<fourthRobot> cleanRobot = make_shared<fourthRobot>();
            for (int i = 0; x < 5; x++) {
                for (int j = 0; y < 5; y++) {
                    cleanRobot->clean(world.world, i, j);
                }
            }
            showWorld(x, y);

        }
    }
    auto endTime = std::chrono::steady_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>
            (endTime - startTime).count();
    std::cout << "Elapsed time: " << elapsed << std::endl;

}