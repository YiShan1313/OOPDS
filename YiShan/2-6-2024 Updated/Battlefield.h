#ifndef Battlefield_H
#define Battlefield_H

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
    void updatePos(Robot* const robot,int ,int);
    bool isEmptyPos(int x, int y) const;
    Robot* getRobot(int x, int y) const;
    int getrow() const { return rows; }
    int getcol() const { return cols; }
};

#endif // BATTLEFIELD_H
