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
    int score;
    int pos_X;
    int pos_Y;

public:
    Robot(string n, int x, int y, int _live) : name(n), live(_live), pos_X(x), pos_Y(y), score(0) {}
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

    virtual string getType() const = 0;

    void setName(const string& n) {
        name = n;
    }

    void setPosition(int x, int y) {
        pos_X = x;
        pos_Y = y;
    }

    int getScore()
    {
        return score;
    }

    void Score()
    {
        score ++;
        cout << getName() << " score " << score << endl;
        if (score == 3)
        {
        }
    }

    int getLive(){
        return live;
    }

    void killed() {
        live --;
        cout << getName() << " your lives left " << live << endl;
        // if (live == 0)
        // {
        //     setPosition(-1, -1);
        //     cout << "dead" << endl;
        // }
        
    }

    virtual bool ableToUpgrade() = 0;


    // virtual void operation(Battlefield &Test)
    // {}


    virtual void operation(Battlefield &Test) = 0;
};

#endif
