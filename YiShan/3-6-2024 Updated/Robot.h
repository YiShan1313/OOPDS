#ifndef Robot_H
#define Robot_H

#include <string>
#include <iostream>
using namespace std;

class Battlefield; 

class Robot {
private:
    string name;
    int live;
    int pos_X;
    int pos_Y;

public:
    Robot() : live(3), pos_X(0), pos_Y(0) {}
    Robot(string n, int x, int y) : name(n), live(3), pos_X(x), pos_Y(y) {}
    virtual ~Robot() {}

    int getPos_X() const {
        return pos_X;
    }
    int getPos_Y() const {
        return pos_Y;
    }

    string getName() const {
        return name;
    }

    void setName(const string& n) {
        name = n;
    }

    void setPosition(int x, int y) {
        pos_X = x;
        pos_Y = y;
    }

    int getLive(){
        return live;
    }

    void killed() {
        live = 0;
        setPosition(-1, -1);
    }

    virtual void operation(Battlefield &Test) = 0;
};

#endif