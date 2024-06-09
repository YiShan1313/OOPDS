#ifndef BATTLEFIELD_H
#define BATTLEFIELD_H

#include <iostream>
using namespace std;

class Robot;

class Battlefield {
    int rows;
    int cols;
    Robot*** grid;

public:
    Battlefield(int r, int c);
    ~Battlefield();
    void display(Robot* Robots[], int numRobots) const;
    void updatePos(Robot* const robot, int prev_X = -1, int prev_Y = -1);
    void clearPos(Robot* const robot);
    bool isEmptyPos(int x, int y) const;
    Robot* getRobot(int x, int y) const;
    int getrow() const { return rows; }
    int getcol() const { return cols; }
};

#endif