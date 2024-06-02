#include <cstdlib>
#include <ctime>
#include <iostream>
#include "Robot.h"
#include "Battlefield.h"
#include "Battlefield.cpp"
using namespace std;

int getRand(int max) {
    return rand() % max;
}

int absValue(int a) {
    return (a < 0) ? -a : a;
}

Robot** seePos(int x, int y, Battlefield &Test);

class MovingRobot : virtual public Robot {
public:
    MovingRobot() : Robot() {}
    void move() {};
};

class ShootingRobot : virtual public Robot {
public:
    ShootingRobot() : Robot() {}
    void fire() {};
};

class SeeingRobot : virtual public Robot {
public:
    SeeingRobot() : Robot() {}
    void see() {};
};

class SteppingRobot : virtual public Robot {
public:
    SteppingRobot() : Robot() {}
    void step() {}
};

class RobotCop : public SeeingRobot, public MovingRobot, public ShootingRobot {
    bool enemyFound = false;

public:
    RobotCop() {
        cout << "RobotCop Created" << endl;
    }

    RobotCop(string n, int x, int y) : Robot(n,x,y){
        cout << "RobotCop Created" << endl;
    }

    ~RobotCop() {
        cout << "~RobotCop Destroyed" << endl;
    }

    Robot** see(Battlefield &Test) {
        cout << "see RobotCop" << endl;
        return seePos(getPos_X(), getPos_Y(), Test);
    }

    void move(Robot** robots, Battlefield &Test) {
        bool existBot = true;
        int moveTo_X = -1;
        int moveTo_Y = -1;

        while(existBot){
            while((moveTo_X > Test.getrow() && moveTo_Y > Test.getcol()) || (moveTo_X < 0 && moveTo_Y < 0)){
                int x = getRand(2) - 1 ;
                int y = getRand(2) - 1 ;

                while(absValue(x) + absValue(y) == 0){
                    x = getRand(2) - 1 ;
                    y = getRand(2) - 1 ;
                }

                moveTo_X = getPos_X() + x;
                moveTo_Y = getPos_Y() + y;
                
                for(int i = 0 ; i < 9 ; i++){
                    if(robots[i] != nullptr){
                        if(robots[i]->getPos_X() == moveTo_X && robots[i]->getPos_Y() == moveTo_Y){
                            existBot = true;
                            cout << "ExistBot True~" << moveTo_X << " , " << moveTo_Y << endl;
                            break;
                        }
                    }

                    existBot = false;
                    cout << "ExistBot False~" << endl;
                }

                cout << "Moving to " << moveTo_X << " , " << moveTo_Y << endl ;
                int prev_X = getPos_X();
                int prev_Y = getPos_Y();
                setPosition(moveTo_X, moveTo_Y);
                Test.updatePos(this, prev_X, prev_Y);
            }
        }

        // if (abs(x) > 1 || abs(y) > 1)
        //     throw "X or Y value is > 1, Can only Move Neighbourhood";
    }

    void fire(int x, int y) {
        if (abs(x) + abs(y) > 10)
            throw "X + Y value is > 10";

        // Get Field Info
        // Kill if exist Robot
    }

    void operation(Battlefield &Test) override;
};

class Terminator : public SeeingRobot, public MovingRobot, public SteppingRobot {
    bool enemyFound = false;

public:
    Terminator() {
        cout << "Terminator Created" << endl;
    }

    Terminator(string n, int x, int y) : Robot(n,x,y) {
        cout << "Terminator Created" << endl;
    }

    ~Terminator() {
        cout << "~Terminator Destroyed" << endl;
    }

    void see(int x, int y) {
        // This robot see its current position only, 再看要不要parameter
        // Move to no-robot position	Means return enemy position to avoid stepping it
        // Get Field Info
        cout << "Okay" << endl;
    }

    void move(int x, int y) {
        if (abs(x) > 1 || abs(y) > 1)
            throw "X or Y value is > 1, Can only Move Neighbourhood";
    }

    void step(int x, int y) {

        // Get Field Info
        // Move to enermy position
        // Kill if exist Robot
    }
};

class TerminatorRoboCop : public SeeingRobot, public MovingRobot, public SteppingRobot, public ShootingRobot {
    bool enemyFound = false;

public:
    TerminatorRoboCop() {
        cout << "TerminatorRoboCop Created" << endl;
    }

    TerminatorRoboCop(string n, int x, int y) : Robot(n,x,y) {
        cout << "TerminatorRoboCop Created" << endl;
    }

    ~TerminatorRoboCop() {
        cout << "~TerminatorRoboCop Destroyed" << endl;
    }

    void see(int x, int y) {
        // This robot see its current position only, 再看要不要parameter
        // Move to no-robot position	Means return enemy position to avoid stepping it
        // Get Field Info
        cout << "Okay" << endl;
    }

    void move(int x, int y) {
        if (abs(x) > 1 || abs(y) > 1)
            throw "X or Y value is > 1, Can only Move Neighbourhood";
    }

    void step(int x, int y) {

        // Get Field Info
        // Move to enermy position
        // Kill if exist Robot
    }

    void fire(int x, int y) {
        if (abs(x) + abs(y) > 10)
            throw "X + Y value is > 10";

        // Get Field Info
        // Kill if exist Robot
    }
};

Robot** seePos(int x, int y, Battlefield &Test){
    Robot** pos = new Robot*[9]{nullptr};

    cout << "seePos Calling at " << x << ", " << y << endl;

    for(int i = 0 ; i < 3 ; i++){
        for(int j = 0 ; j < 3 ; j++){
            int pos_x = x+i-1;
            int pos_y = y+j-1;

            if(pos_x >= 0 && pos_y >= 0 && pos_x < Test.getrow() && pos_y < Test.getcol()){
                cout << "Current X: " << pos_x << " Current Y: " << pos_y << endl;
                pos[i+j] = Test.getRobot(pos_x, pos_y);
                if(pos[i+j] != nullptr){
                    cout << pos[i+j]->getName() << endl;
                }
            }
        }
    }
    
    return pos;
}

void RobotCop::operation(Battlefield &Test){
    Robot** pos = see(Test);
    // for(int i = 0 ; i < 9 ; i++){
        // if(pos[i] != nullptr){
        //     cout << pos[i]->getName() << endl;
        // }
    // }
    move(pos, Test);
    
    // cout << "----" << Test.isEmptyPos(0,0);
}

int main() {
    srand (time(0));

    int field_X = 10;
    int field_Y = 10;
	Battlefield Test(field_X, field_Y);

    int numRobots = getRand(10);

    cout << numRobots << endl;

    Robot* robots[numRobots];

    for (int i = 0; i < numRobots; i++) {
        int x = getRand(10) % field_X;
        int y = getRand(10) % field_Y;

        while(!Test.isEmptyPos(x, y)){
            x = getRand(10) % field_X;
            y = getRand(10) % field_Y;
        }

        robots[i] = new RobotCop(to_string(i), x, y);
        Test.updatePos(robots[i]);
    }

    Test.display(robots, numRobots);

    for (int i = 0; i < numRobots; i++) {
        // cout << "(" << robots[i]->getPos_X() << " , " << robots[i]->getPos_Y() << ")" << endl;
        robots[i]->operation(Test);
    }

	// RobotCop A("A", rand()%field_X,rand()%field_Y);
	// RobotCop B("B", rand()%field_X,rand()%field_Y);

    // Robot* robots[] = { &A, &B };
    // int numRobots = sizeof(robots) / sizeof(robots[0]);

	Test.display(robots, numRobots);

    // TerminatorRoboCop A;
    // A.see(0,0);

    for(int i = 0; i < numRobots; i++) {
        delete robots[i];
    }

	return 0;
}