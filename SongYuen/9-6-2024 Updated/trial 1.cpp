// 1211111313 Yee Sung Yuen
// 1221102684 Wong Yi Shan
// 1231301176 Eric Man Lik Hong

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include "Robot.h"
#include "Battlefield.h"
using namespace std;

int getRand(int max) 
{
    return rand() % (max + 1);
}

int absValue(int a) 
{
    return (a < 0) ? -a : a;
}

Robot** seePos(int x, int y, Battlefield &Test);

class MovingRobot : virtual public Robot {
public:
    MovingRobot(){}
    void move() {};
};

class ShootingRobot : virtual public Robot {
public:
    ShootingRobot() {}
    void fire() {};
};

class SeeingRobot : virtual public Robot {
public:
    SeeingRobot() {}
    void see() {};
};

class SteppingRobot : virtual public Robot {
public:
    SteppingRobot() {}
    void step() {}
};

class Terminator : public SeeingRobot, public MovingRobot, public SteppingRobot 
{
    private:
        int killCount{0};

    public:

        Terminator(string n, int x, int y, int _live) : Robot(n,x,y,_live) 
        {
            cout << "Terminator Created" << endl;
        }

        ~Terminator() 
        {
            cout << "~Terminator Destroyed" << endl;
        }

        Robot** see(Battlefield &Test) 
        {
            cout << "see Terminator" << endl;
            return seePos(getPos_X(), getPos_Y(), Test);
        }

        void move(Robot** robots, Battlefield &Test) 
        {
            cout << "Terminator" << getName() << " Just Moving As No Robot To Step~" << endl ;

            int counter = 0;
            for(int i = 0 ; i < 9 ; i++)
            {
                if(robots[i] != nullptr)
                {
                    counter++;
                }
            }

            if((Test.getcol() - 1 == getPos_X() && Test.getrow() - 1 == getPos_Y()) || (getPos_X() == 0 && Test.getrow() - 1 == getPos_Y()) || (Test.getcol() - 1 == getPos_X() && getPos_Y() == 0) || (getPos_X() == 0 && getPos_Y() == 0))
            {
                // cout << counter;
                if(counter == 4)
                {
                    cout << "Robot" << getName() << " Cant Move As No Empty Space Surrounding !" << endl ;
                    return;
                }
            }
            else if(Test.getcol() - 1 == getPos_X() || Test.getrow() - 1 == getPos_Y() || getPos_X() == 0 || getPos_Y() == 0)
            {
                // cout << counter;
                if(counter == 6)
                {
                    cout << "Robot" << getName() << " Cant Move As No Empty Space Surrounding !" << endl ;
                    return;
                }
            }
            else
            {
                // cout << counter;
                if(counter == 9)
                {
                    cout << "Robot" << getName() << " Cant Move As No Empty Space Surrounding !" << endl ;
                    return;
                }
            }


            cout << "move Terminator" << endl;
            bool existBot = true;
            int moveTo_X = -1;
            int moveTo_Y = -1;

            while(existBot)
            {
                int x = getRand(2) - 1 ;
                int y = getRand(2) - 1 ;
                moveTo_X = getPos_X() + x;
                moveTo_Y = getPos_Y() + y;

                while(moveTo_X >= Test.getrow() || moveTo_Y >= Test.getcol() || moveTo_X < 0 || moveTo_Y < 0 || (x == 0 && y == 0))
                {
                    x = getRand(2) - 1;
                    y = getRand(2) - 1;
                    moveTo_X = getPos_X() + x;
                    moveTo_Y = getPos_Y() + y;
                }

                // cout << "Trying to Move to (" << moveTo_X << " , " << moveTo_Y << ")" << endl;
                
                for(int i = 0 ; i < 9 ; i++)
                {
                    if(robots[i] != nullptr)
                    {
                        if(robots[i]->getPos_X() == moveTo_X && robots[i]->getPos_Y() == moveTo_Y)
                        {
                            existBot = true;
                            // cout << "ExistBot True~" << moveTo_X << " , " << moveTo_Y << endl;
                            break;
                        }
                    }

                    existBot = false;
                    // cout << "ExistBot False~" << endl;
                }
            }

            cout << "Robot" << getName() << " Moving to " << moveTo_X << " , " << moveTo_Y << endl;
            int prev_X = getPos_X();
            int prev_Y = getPos_Y();
            setPosition(moveTo_X, moveTo_Y);
            Test.updatePos(this, prev_X, prev_Y);
        }

        void step(Robot** robots, Battlefield &Test)
        {
            int counter = 0;
            for(int i = 0 ; i < 9 ; i++)
            {

                if(robots[i] != nullptr)
                {
                    counter++;
                }
            }

            if((Test.getcol() - 1 == getPos_X() && Test.getrow() - 1 == getPos_Y()) || (getPos_X() == 0 && Test.getrow() - 1 == getPos_Y()) || (Test.getcol() - 1 == getPos_X() && getPos_Y() == 0) || (getPos_X() == 0 && getPos_Y() == 0))
            {
                // cout << counter;
                if(counter == 4)
                {
                    cout << "Robot" << getName() << " Cant Move As No Empty Space Surrounding !" << endl ;
                    return;
                }
            }
            else if(Test.getcol() - 1 == getPos_X() || Test.getrow() - 1 == getPos_Y() || getPos_X() == 0 || getPos_Y() == 0)
            {
                // cout << counter;
                if(counter == 6)
                {
                    cout << "Robot" << getName() << " Cant Move As No Empty Space Surrounding !" << endl ;
                    return;
                }
            }
            else
            {
                // cout << counter;
                if(counter == 9)
                {
                    cout << "Robot" << getName() << " Cant Move As No Empty Space Surrounding !" << endl ;
                    return;
                }
            }


            cout << "step Terminator" << endl;
            bool existBot = false;
            int moveTo_X = -1;
            int moveTo_Y = -1;
            Robot*  robotFound = nullptr;

            cout << counter << endl ;

            //Check If there is any robot surrounding to step, else just move
            if(counter != 1){
                while(!existBot)
                {
                    int x = getRand(2) - 1 ;
                    int y = getRand(2) - 1 ;
                    moveTo_X = getPos_X() + x;
                    moveTo_Y = getPos_Y() + y;

                    while(moveTo_X >= Test.getrow() || moveTo_Y >= Test.getcol() || moveTo_X < 0 || moveTo_Y < 0 || (x == 0 && y == 0))
                    {
                        x = getRand(2) - 1 ;
                        y = getRand(2) - 1 ;
                        moveTo_X = getPos_X() + x;
                        moveTo_Y = getPos_Y() + y;
                    }

                    // cout << "Trying to Move to (" << moveTo_X << " , " << moveTo_Y << ")" << endl;
                    
                    for(int i = 0 ; i < 9 ; i++)
                    {
                        if(robots[i] != nullptr)
                        {
                            if(robots[i]->getPos_X() == moveTo_X && robots[i]->getPos_Y() == moveTo_Y)
                            {
                                existBot = true;
                                robotFound = robots[i];
                                // cout << "ExistBot True~" << moveTo_X << " , " << moveTo_Y << endl;
                                break;
                            }
                        }

                        existBot = false;
                        // cout << "ExistBot False~" << endl;
                    }
                }

                cout << "Robot" << getName() << " Stepping to Robot" << robotFound->getName() << " on Position " << moveTo_X << " , " << moveTo_Y << endl;
                int prev_X = getPos_X();
                int prev_Y = getPos_Y();

                robotFound->killed();
                if(robotFound->getLive() == 0)
                    Test.clearPos(robotFound);

                setPosition(moveTo_X, moveTo_Y);
                Test.updatePos(this, prev_X, prev_Y);
                killCount++;
                cout << "KillCount " << killCount << endl << endl;
            }
            else{
                move(robots, Test);
            }

            
        }

        void inform()
        {
            cout << "I have upgraded" << endl;
        }

        bool ableToUpgrade() override{
            // Add to check killedcount later
            return (getLive() != 0);
        }
        
        string getType() const {
            return "Terminator";
        }

        void operation(Battlefield &Test) override
        {
            // IF this robot alive, then do, else skip...
            if(getLive() == 0)
            {   
                cout << "Robot " << getName() << " is Death, Skip This Turn" << endl << endl ; 
                return ;
            }

            cout << "Robot" << getName() << " Live: " << getLive() << endl;
            
            Robot** pos = see(Test);
            // for(int i = 0 ; i < 9 ; i++){
            //     if(pos[i] != nullptr){
            //         cout << pos[i]->getName() << endl;
            //     }
            // }
            // move(pos, Test);
            step(pos, Test);
            // cout << " terminator is call " << endl;
            
            // cout << "----" << Test.isEmptyPos(0,0);
        }

};

class RobotCop : public SeeingRobot, public MovingRobot, public ShootingRobot 
{
    private:
        int killCount{0};
        //bool isUpgraded;

    public:
        RobotCop(string n, int x, int y, int _live) : Robot(n,x,y,_live)
        {
            cout << "RobotCop Created" << endl;
        }

        ~RobotCop() 
        {
            cout << "~RobotCop Destroyed" << endl;
        }

        Robot** see(Battlefield &Test) 
        {
            cout << "see RobotCop" << endl;
            return seePos(getPos_X(), getPos_Y(), Test);
        }

        void move(Robot** robots, Battlefield &Test) 
        {
            int counter = 0;
            for(int i = 0 ; i < 9 ; i++)
            {
                if(robots[i] != nullptr)
                {
                    counter++;
                }
            }

            if((Test.getcol() - 1 == getPos_X() && Test.getrow() - 1 == getPos_Y()) || (getPos_X() == 0 && Test.getrow() - 1 == getPos_Y()) || (Test.getcol() - 1 == getPos_X() && getPos_Y() == 0) || (getPos_X() == 0 && getPos_Y() == 0))
            {
                // cout << counter;
                if(counter == 4)
                {
                    cout << "Robot" << getName() << " Cant Move As No Empty Space Surrounding !" << endl ;
                    return;
                }
            }
            else if(Test.getcol() - 1 == getPos_X() || Test.getrow() - 1 == getPos_Y() || getPos_X() == 0 || getPos_Y() == 0)
            {
                // cout << counter;
                if(counter == 6)
                {
                    cout << "Robot" << getName() << " Cant Move As No Empty Space Surrounding !" << endl ;
                    return;
                }
            }
            else
            {
                // cout << counter;
                if(counter == 9)
                {
                    cout << "Robot" << getName() << " Cant Move As No Empty Space Surrounding !" << endl ;
                    return;
                }
            }


            cout << "move RobotCop" << endl;
            bool existBot = true;
            int moveTo_X = -1;
            int moveTo_Y = -1;

            while(existBot)
            {
                int x = getRand(2) - 1 ;
                int y = getRand(2) - 1 ;
                moveTo_X = getPos_X() + x;
                moveTo_Y = getPos_Y() + y;

                //解决会move/step同一个地方
                while(moveTo_X >= Test.getrow() || moveTo_Y >= Test.getcol() || moveTo_X < 0 || moveTo_Y < 0 || (x == 0 && y == 0))
                {   
                    // cout << x << " " << y << endl;
                    x = getRand(2) - 1 ;
                    y = getRand(2) - 1 ;
                    moveTo_X = getPos_X() + x;
                    moveTo_Y = getPos_Y() + y;
                }

                // cout << "Trying to Move to (" << moveTo_X << " , " << moveTo_Y << ")" << endl;
                
                for(int i = 0 ; i < 9 ; i++)
                {
                    if(robots[i] != nullptr)
                    {
                        if(robots[i]->getPos_X() == moveTo_X && robots[i]->getPos_Y() == moveTo_Y)
                        {
                            existBot = true;
                            // cout << "ExistBot True~" << moveTo_X << " , " << moveTo_Y << endl;
                            break;
                        }
                    }

                    existBot = false;
                    // cout << "ExistBot False~" << endl;
                }
            }

            cout << "Robot" << getName() << " Moving to " << moveTo_X << " , " << moveTo_Y << endl;
            int prev_X = getPos_X();
            int prev_Y = getPos_Y();
            setPosition(moveTo_X, moveTo_Y);
            Test.updatePos(this, prev_X, prev_Y);
        }

        void fire(Robot** robots, Battlefield &Test) 
        {
            int fire_X, fire_Y, x = 0, y = 0;
            while(fire_X >= Test.getrow() || fire_Y >= Test.getcol() || fire_X < 0 || fire_Y < 0 || (x == 0 && y == 0))
            {
                x = getRand(20) - 10;
                int y_Range = 10 - absValue(x);
                y = getRand(1) == 0 ? y_Range : -y_Range; // Random +/-

                fire_X = x + getPos_X();
                fire_Y = y + getPos_Y();
            }
            
            cout << "X: " << fire_X << " Y: " << fire_Y << endl << endl;

            Robot* shoot = Test.getRobot(fire_X, fire_Y);

            if(shoot != nullptr)
            {
                cout << getName() << " --Shoot--> " << shoot->getName() << endl;
                shoot->killed();
                if(shoot->getLive() == 0)
                    Test.clearPos(shoot);
                killCount++;
                cout << "KillCount " << killCount << endl << endl;
            }

            // Get Field Info
            // Kill if exist Robot
        }

        bool ableToUpgrade()override{
            // Add to check killedcount later
            return (getLive() != 0);
        }

        // void upgrade(Robot** robots, Battlefield &Test) 
        // {
        //     if (killCount == 3 && !isUpgraded) {
        //         // Perform Upgrade Logic
        //         isUpgraded = true;
        //         cout << getName() << " Upgraded to Terminator!" << endl;
        //         // (Optional) Call a separate function to handle specific changes
        //         Terminator(robots, Test);
        //     }
        // }

        string getType() const {
            return "RoboCop";
        }

        void operation(Battlefield &Test) override
        {
            // IF this robot alive, then do, else skip...
            if(getLive() == 0)
            {
                cout << "Robot " << getName() << " is Death, Skip This Turn" << endl << endl ; 
                return ;
            }
            
            Robot** pos = see(Test);
            // for(int i = 0 ; i < 9 ; i++){
            //     if(pos[i] != nullptr){
            //         cout << pos[i]->getName() << endl;
            //     }
            // }
            move(pos, Test);
            fire(pos, Test);
            
            // cout << "----" << Test.isEmptyPos(0,0);
        }
};

class BlueThunder : public SeeingRobot, public MovingRobot, public SteppingRobot 
{
    private:
        int killCount{0};

    public:

        BlueThunder(string n, int x, int y, int _live) : Robot(n,x,y,_live) {
            cout << "BlueThunder Created" << endl;
        }

        ~BlueThunder() {
            cout << "~BlueThunder Destroyed" << endl;
        }

        Robot** see(Battlefield &Test) 
        {
            cout << "see BlueThunder" << endl;
            return seePos(getPos_X(), getPos_Y(), Test);
        }

        void fire(Robot** robots, Battlefield &Test) 
        {
            int fire_X, fire_Y;
            int direction = 0;

            do {
                switch (direction)
                {
                    case 0: // Up
                        fire_X = getPos_X() - 1;
                        fire_Y = getPos_Y();
                        break;
                    case 1: // Right
                        fire_X = getPos_X();
                        fire_Y = getPos_Y() + 1;
                        break;
                    case 2: // Down
                        fire_X = getPos_X() + 1;
                        fire_Y = getPos_Y();
                        break;
                    case 3: // Left
                        fire_X = getPos_X();
                        fire_Y = getPos_Y() - 1;
                        break;
                }

                direction = (direction + 1) % 4; 
            } while(fire_X >= Test.getrow() || fire_Y >= Test.getcol() || fire_X < 0 || fire_Y < 0);

            cout << "X: " << fire_X << " Y: " << fire_Y << endl << endl;

            Robot* shoot = Test.getRobot(fire_X, fire_Y);

            if(shoot != nullptr)
            {
                cout << getName() << " --Shoot--> " << shoot->getName() << endl << endl ;
                Test.clearPos(shoot);
                shoot->killed();
                killCount++;
                cout << "score " << killCount << endl << endl;
                // if (killCount >= 3) 
                // {
                //     upgradeToTerminator();
                // }
            
            }

            // Get Field Info
            // Kill if exist Robot
        }

        bool ableToUpgrade()override{
            return false;
        }

        string getType() const {
            return "BlueThunder";
        }

        void operation(Battlefield &Test)
        {
            // IF this robot alive, then do, else skip...
            if(getLive() == 0)
            {
                cout << "Robot " << getName() << " is Death, Skip This Turn" << endl << endl ; 
                return ;
            }
            
            Robot** pos = see(Test);
            // for(int i = 0 ; i < 9 ; i++){
            //     if(pos[i] != nullptr){
            //         cout << pos[i]->getName() << endl;
            //     }
            // }
            //move(pos, Test);
            fire(pos, Test);
            
            // cout << "----" << Test.isEmptyPos(0,0);
        }

};

Robot** seePos(int x, int y, Battlefield &Test)
{
    cout << "Seeing : " << x << " , " << y << endl;
    Robot** pos = new Robot*[9]{nullptr};

    // cout << "seePos Calling at " << x << ", " << y << endl;

    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            int pos_x = x+i-1;
            int pos_y = y+j-1;

            if(pos_x >= 0 && pos_y >= 0 && pos_x < Test.getrow() && pos_y < Test.getcol())
            {
                // cout << "Current X: " << pos_x << " Current Y: " << pos_y << endl;
                int index = i * 3 + j;
                pos[index] = Test.getRobot(pos_x, pos_y);
                if(pos[index] != nullptr)
                {
                    // cout << index << endl ;
                    // cout << pos[index]->getName() << endl;
                }
            }
        }
    }
    
    return pos;
}

class TerminatorRoboCop : public SeeingRobot, public MovingRobot, public SteppingRobot, public ShootingRobot 
{
    private:
        int killCount{0};

    public:

        TerminatorRoboCop(string n, int x, int y, int _live) : Robot(n,x,y,_live) 
        {
            cout << "Terminator Created" << endl;
        }

        ~TerminatorRoboCop() 
        {
            cout << "~Terminator Destroyed" << endl;
        }

        Robot** see(Battlefield &Test) 
        {
            cout << "see TerminatorRoboCop" << endl;
            return seePos(getPos_X(), getPos_Y(), Test);
        }

        void move(Robot** robots, Battlefield &Test) 
        {
            cout << "TerminatorRoboCop" << getName() << " Just Moving As No Robot To Step~" << endl ;

            int counter = 0;
            for(int i = 0 ; i < 9 ; i++)
            {
                if(robots[i] != nullptr)
                {
                    counter++;
                }
            }

            if((Test.getcol() - 1 == getPos_X() && Test.getrow() - 1 == getPos_Y()) || (getPos_X() == 0 && Test.getrow() - 1 == getPos_Y()) || (Test.getcol() - 1 == getPos_X() && getPos_Y() == 0) || (getPos_X() == 0 && getPos_Y() == 0))
            {
                // cout << counter;
                if(counter == 4)
                {
                    cout << "Robot" << getName() << " Cant Move As No Empty Space Surrounding !" << endl ;
                    return;
                }
            }
            else if(Test.getcol() - 1 == getPos_X() || Test.getrow() - 1 == getPos_Y() || getPos_X() == 0 || getPos_Y() == 0)
            {
                // cout << counter;
                if(counter == 6)
                {
                    cout << "Robot" << getName() << " Cant Move As No Empty Space Surrounding !" << endl ;
                    return;
                }
            }
            else
            {
                // cout << counter;
                if(counter == 9)
                {
                    cout << "Robot" << getName() << " Cant Move As No Empty Space Surrounding !" << endl ;
                    return;
                }
            }


            cout << "move TerminatorRoboCop" << endl;
            bool existBot = true;
            int moveTo_X = -1;
            int moveTo_Y = -1;

            while(existBot)
            {
                int x = getRand(2) - 1 ;
                int y = getRand(2) - 1 ;
                moveTo_X = getPos_X() + x;
                moveTo_Y = getPos_Y() + y;

                while(moveTo_X >= Test.getrow() || moveTo_Y >= Test.getcol() || moveTo_X < 0 || moveTo_Y < 0 || (x == 0 && y == 0))
                {
                    x = getRand(2) - 1;
                    y = getRand(2) - 1;
                    moveTo_X = getPos_X() + x;
                    moveTo_Y = getPos_Y() + y;
                }

                // cout << "Trying to Move to (" << moveTo_X << " , " << moveTo_Y << ")" << endl;
                
                for(int i = 0 ; i < 9 ; i++)
                {
                    if(robots[i] != nullptr)
                    {
                        if(robots[i]->getPos_X() == moveTo_X && robots[i]->getPos_Y() == moveTo_Y)
                        {
                            existBot = true;
                            // cout << "ExistBot True~" << moveTo_X << " , " << moveTo_Y << endl;
                            break;
                        }
                    }

                    existBot = false;
                    // cout << "ExistBot False~" << endl;
                }
            }

            cout << "TerminatorRoboCop" << getName() << " Moving to " << moveTo_X << " , " << moveTo_Y << endl;
            int prev_X = getPos_X();
            int prev_Y = getPos_Y();
            setPosition(moveTo_X, moveTo_Y);
            Test.updatePos(this, prev_X, prev_Y);
        }

        void step(Robot** robots, Battlefield &Test)
        {
            int counter = 0;
            for(int i = 0 ; i < 9 ; i++)
            {

                if(robots[i] != nullptr)
                {
                    counter++;
                }
            }

            if((Test.getcol() - 1 == getPos_X() && Test.getrow() - 1 == getPos_Y()) || (getPos_X() == 0 && Test.getrow() - 1 == getPos_Y()) || (Test.getcol() - 1 == getPos_X() && getPos_Y() == 0) || (getPos_X() == 0 && getPos_Y() == 0))
            {
                // cout << counter;
                if(counter == 4)
                {
                    cout << "Robot" << getName() << " Cant Move As No Empty Space Surrounding !" << endl ;
                    return;
                }
            }
            else if(Test.getcol() - 1 == getPos_X() || Test.getrow() - 1 == getPos_Y() || getPos_X() == 0 || getPos_Y() == 0)
            {
                // cout << counter;
                if(counter == 6)
                {
                    cout << "Robot" << getName() << " Cant Move As No Empty Space Surrounding !" << endl ;
                    return;
                }
            }
            else
            {
                // cout << counter;
                if(counter == 9)
                {
                    cout << "Robot" << getName() << " Cant Move As No Empty Space Surrounding !" << endl ;
                    return;
                }
            }


            cout << "step TerminatorRoboCop" << endl;
            bool existBot = false;
            int moveTo_X = -1;
            int moveTo_Y = -1;
            Robot*  robotFound = nullptr;

            cout << counter << endl ;

            //Check If there is any robot surrounding to step, else just move
            if(counter != 1){
                while(!existBot)
                {
                    int x = getRand(2) - 1 ;
                    int y = getRand(2) - 1 ;
                    moveTo_X = getPos_X() + x;
                    moveTo_Y = getPos_Y() + y;

                    while(moveTo_X >= Test.getrow() || moveTo_Y >= Test.getcol() || moveTo_X < 0 || moveTo_Y < 0 || (x == 0 && y == 0))
                    {
                        x = getRand(2) - 1 ;
                        y = getRand(2) - 1 ;
                        moveTo_X = getPos_X() + x;
                        moveTo_Y = getPos_Y() + y;
                    }

                    // cout << "Trying to Move to (" << moveTo_X << " , " << moveTo_Y << ")" << endl;
                    
                    for(int i = 0 ; i < 9 ; i++)
                    {
                        if(robots[i] != nullptr)
                        {
                            if(robots[i]->getPos_X() == moveTo_X && robots[i]->getPos_Y() == moveTo_Y)
                            {
                                existBot = true;
                                robotFound = robots[i];
                                // cout << "ExistBot True~" << moveTo_X << " , " << moveTo_Y << endl;
                                break;
                            }
                        }

                        existBot = false;
                        // cout << "ExistBot False~" << endl;
                    }
                }

                cout << "TerminatorRoboCop" << getName() << " Stepping to Robot" << robotFound->getName() << " on Position " << moveTo_X << " , " << moveTo_Y << endl;
                int prev_X = getPos_X();
                int prev_Y = getPos_Y();

                robotFound->killed();
                if(robotFound->getLive() == 0)
                    Test.clearPos(robotFound);

                setPosition(moveTo_X, moveTo_Y);
                Test.updatePos(this, prev_X, prev_Y);
                killCount++;
                cout << "KillCount " << killCount << endl << endl;
            }
            else{
                move(robots, Test);
            }

            
        }

        void fire(Robot** robots, Battlefield &Test) 
        {
            int fire_X, fire_Y, x = 0, y = 0;
            while(fire_X >= Test.getrow() || fire_Y >= Test.getcol() || fire_X < 0 || fire_Y < 0 || (x == 0 && y == 0))
            {
                x = getRand(20) - 10;
                int y_Range = 10 - absValue(x);
                y = getRand(1) == 0 ? y_Range : -y_Range; // Random +/-

                fire_X = x + getPos_X();
                fire_Y = y + getPos_Y();
            }
            
            cout << "X: " << fire_X << " Y: " << fire_Y << endl << endl;

            Robot* shoot = Test.getRobot(fire_X, fire_Y);

            if(shoot != nullptr)
            {
                cout << getName() << " --Shoot--> " << shoot->getName() << endl;
                shoot->killed();
                if(shoot->getLive() == 0)
                    Test.clearPos(shoot);
                killCount++;
                cout << "KillCount " << killCount << endl << endl;
            }

            // Get Field Info
            // Kill if exist Robot
        }

        void inform()
        {
            cout << "I have upgraded" << endl;
        }

        bool ableToUpgrade() override{
            // Add to check killedcount later
            return (getLive() != 0);
        }
        
        string getType() const {
            return "TerminatorRoboCop";
        }

        void operation(Battlefield &Test) override
        {
            // IF this robot alive, then do, else skip...
            if(getLive() == 0)
            {   
                cout << "Robot " << getName() << " is Death, Skip This Turn" << endl << endl ; 
                return ;
            }

            cout << "Robot" << getName() << " Live: " << getLive() << endl;
            
            Robot** pos = see(Test);
            // for(int i = 0 ; i < 9 ; i++){
            //     if(pos[i] != nullptr){
            //         cout << pos[i]->getName() << endl;
            //     }
            // }
            // move(pos, Test);
            step(pos, Test);
            fire(pos, Test);
            // cout << " terminator is call " << endl;
            
            // cout << "----" << Test.isEmptyPos(0,0);
        }

};

class Madbot : public SeeingRobot, public MovingRobot, public ShootingRobot 
{
    private:
        int killCount{0};

    public:
        Madbot(string n, int x, int y, int _live) : Robot(n,x,y,_live){
            cout << "Madbot Created" << endl;
        }

        ~Madbot() {
            cout << "~Madbot Destroyed" << endl;
        }

        Robot** see(Battlefield &Test) {
            cout << "see Madbot" << endl;
            return seePos(getPos_X(), getPos_Y(), Test);
        }

        void fire(Robot** robots, Battlefield &Test) {
            int fire_X, fire_Y, x = 0, y = 0;

            while(fire_X >= Test.getrow() || fire_Y >= Test.getcol() || fire_X < 0 || fire_Y < 0 || (x == 0 && y == 0)){
                x = getRand(20) - 2;
                int y_Range = 2 - absValue(x);
                y = getRand(2 * y_Range + 1) - y_Range; // 2*yrange give double of the range, then - the range give random + / - num

                fire_X = x + getPos_X();
                fire_Y = y + getPos_Y();
            }
            
            cout << "X: " << fire_X << " Y: " << fire_Y << endl << endl;

            Robot* shoot = Test.getRobot(fire_X, fire_Y);

            if(shoot != nullptr){
                cout << getName() << " --Shoot--> " << shoot->getName() << endl << endl;
                Test.clearPos(shoot);
                killCount++;
                cout << "score " << killCount << endl << endl;
                // if (killCount >= 3) 
                // {
                //     upgradeToTerminator();
                // }
            }

            // Get Field Info
            // Kill if exist Robot
        }

        bool ableToUpgrade()override{
            return false;
        }

        string getType() const {
            return "Madbot";
        }

        void operation(Battlefield &Test)
        {
            // IF this robot alive, then do, else skip...
            if(getLive() == 0)
            {
                cout << "Robot " << getName() << " is Death, Skip This Turn" << endl << endl ; 
                return ;
            }
            
            Robot** pos = see(Test);
            // for(int i = 0 ; i < 9 ; i++){
            //     if(pos[i] != nullptr){
            //         cout << pos[i]->getName() << endl;
            //     }
            // }
            //move(pos, Test);
            fire(pos, Test);
            
            // cout << "----" << Test.isEmptyPos(0,0);
        }
};

class RoboTank : public SeeingRobot, public MovingRobot, public ShootingRobot 
{
    private:
        int killCount{0};

    public:
        RoboTank(string n, int x, int y, int _live) : Robot(n,x,y,_live){
            cout << "RoboTank Created" << endl;
        }

        ~RoboTank() {
            cout << "~RoboTank Destroyed" << endl;
        }

        Robot** see(Battlefield &Test) {
            cout << "see RoboTank" << endl;
            return seePos(getPos_X(), getPos_Y(), Test);
        }

        void fire(Robot** robots, Battlefield &Test) {
            int fire_X, fire_Y, x = getRand(20), y = getRand(20);

            while(fire_X >= Test.getrow() || fire_Y >= Test.getcol() || fire_X < 0 || fire_Y < 0 || (x == 0 && y == 0)){
                x = getRand(20) - 10;
                int y_Range = 10 - absValue(x);
                y = getRand(1) == 0 ? y_Range : -y_Range; // 2*yrange give double of the range, then - the range give random + / - num

                fire_X = x + getPos_X();
                fire_Y = y + getPos_Y();
            }
            
            cout << "X: " << fire_X << " Y: " << fire_Y << endl << endl;

            Robot* shoot = Test.getRobot(fire_X, fire_Y);

            if(shoot != nullptr){
                cout << getName() << " --Shoot--> " << shoot->getName() << endl << endl;
                Test.clearPos(shoot);
                shoot->killed();
                killCount++;
                cout << "score " << killCount << endl << endl;
                // if (killCount >= 3) 
                // {
                //     upgradeToTerminator();
                // }
            }

            // Get Field Info
            // Kill if exist Robot
        }

        bool ableToUpgrade()override{
            return false;
        }

        string getType() const {
            return "RoboTank";
        }

        void operation(Battlefield &Test)
        {
            // IF this robot alive, then do, else skip...
            if(getLive() == 0)
            {
                cout << "Robot " << getName() << " is Death, Skip This Turn" << endl << endl ; 
                return ;
            }
            
            Robot** pos = see(Test);
            // for(int i = 0 ; i < 9 ; i++){
            //     if(pos[i] != nullptr){
            //         cout << pos[i]->getName() << endl;
            //     }
            // }
            //move(pos, Test);
            fire(pos, Test);
            
            // cout << "----" << Test.isEmptyPos(0,0);
        }
};

class UltimateRobot : public SeeingRobot, public MovingRobot, public ShootingRobot 
{
    private:
        int killCount{0};
public:
    UltimateRobot(string n, int x, int y, int _live) : Robot(n,x,y,_live)
    {
        cout << "UltimateRobot Created" << endl;
    }

    ~UltimateRobot() 
    {
        cout << "~UltimateRobot Destroyed" << endl;
    }

    Robot** see(Battlefield &Test) 
    {
        cout << "see UltimateRobot" << endl;
        return seePos(getPos_X(), getPos_Y(), Test);
    }

        void move(Robot** robots, Battlefield &Test) 
        {
            int counter = 0;
            for(int i = 0 ; i < 9 ; i++)
            {
                if(robots[i] != nullptr)
                {
                    counter++;
                }
            }

            if((Test.getcol() - 1 == getPos_X() && Test.getrow() - 1 == getPos_Y()) || (getPos_X() == 0 && Test.getrow() - 1 == getPos_Y()) || (Test.getcol() - 1 == getPos_X() && getPos_Y() == 0) || (getPos_X() == 0 && getPos_Y() == 0))
            {
                // cout << counter;
                if(counter == 4)
                {
                    cout << "Robot" << getName() << " Cant Move As No Empty Space Surrounding !" << endl ;
                    return;
                }
            }
            else if(Test.getcol() - 1 == getPos_X() || Test.getrow() - 1 == getPos_Y() || getPos_X() == 0 || getPos_Y() == 0)
            {
                // cout << counter;
                if(counter == 6)
                {
                    cout << "Robot" << getName() << " Cant Move As No Empty Space Surrounding !" << endl ;
                    return;
                }
            }
            else
            {
                // cout << counter;
                if(counter == 9)
                {
                    cout << "Robot" << getName() << " Cant Move As No Empty Space Surrounding !" << endl ;
                    return;
                }
            }


            cout << "move UltimateRobot" << endl;
            bool existBot = true;
            int moveTo_X = -1;
            int moveTo_Y = -1;

            while(existBot)
            {
                int x = getRand(2) - 1 ;
                int y = getRand(2) - 1 ;
                moveTo_X = getPos_X() + x;
                moveTo_Y = getPos_Y() + y;

                while(moveTo_X >= Test.getrow() || moveTo_Y >= Test.getcol() || moveTo_X < 0 || moveTo_Y < 0)
                {
                    x = getRand(2) - 1;
                    y = getRand(2) - 1;
                    moveTo_X = getPos_X() + x;
                    moveTo_Y = getPos_Y() + y;
                }

                // cout << "Trying to Move to (" << moveTo_X << " , " << moveTo_Y << ")" << endl;
                
                for(int i = 0 ; i < 9 ; i++)
                {
                    if(robots[i] != nullptr)
                    {
                        if(robots[i]->getPos_X() == moveTo_X && robots[i]->getPos_Y() == moveTo_Y)
                        {
                            existBot = true;
                            // cout << "ExistBot True~" << moveTo_X << " , " << moveTo_Y << endl;
                            break;
                        }
                    }

                    existBot = false;
                    // cout << "ExistBot False~" << endl;
                }
            }

            cout << "Robot" << getName() << " Moving to " << moveTo_X << " , " << moveTo_Y << endl;
            int prev_X = getPos_X();
            int prev_Y = getPos_Y();
            setPosition(moveTo_X, moveTo_Y);
            Test.updatePos(this, prev_X, prev_Y);
        }

        void step(Robot** robots, Battlefield &Test) {
            bool existBot = true;
            int moveTo_X = -1;
            int moveTo_Y = -1;

            while(existBot){
                int x = getRand(2) - 1 ;
                int y = getRand(2) - 1 ;
                moveTo_X = getPos_X() + x;
                moveTo_Y = getPos_Y() + y;

                // cout << "Trying to Move to (" << moveTo_X << " , " << moveTo_Y << ")" << endl;
                
                for(int i = 0 ; i < 9 ; i++)
                {
                    if(robots[i] != nullptr)
                    {
                        if(robots[i]->getPos_X() == moveTo_X && robots[i]->getPos_Y() == moveTo_Y)
                        {
                            Robot* step = Test.getRobot(moveTo_X, moveTo_Y);

                            if(step != nullptr && step != this)
                            {
                                cout << getName() << " --Step--> " << step->getName() << endl << endl ;
                                Test.clearPos(step);
                                step->killed();
                                killCount++;
                                cout << "score " << killCount << endl << endl;
                                // if (killCount >= 3) 
                                // {
                                //     upgradeToTerminator();
                                // }
                            
                            }
                            // cout << "ExistBot True~" << moveTo_X << " , " << moveTo_Y << endl;
                            break;
                        }
                    }

                    existBot = false;
                    // cout << "ExistBot False~" << endl;
                }
            }
        }

        void fire(Robot** robots, Battlefield &Test) 
        {
            int fire_X, fire_Y, x = 0, y = 0;

            while(fire_X >= Test.getrow() || fire_Y >= Test.getcol() || fire_X < 0 || fire_Y < 0 || (x == 0 && y == 0))
            {
                for (int i = 0; i < 3; i++)
                {
                    x = getRand(20) - 10;
                    int y_Range = 10 - absValue(x);
                    y = getRand(2 * y_Range + 1) - y_Range; // 2*yrange give double of the range, then - the range give random + / - num

                    fire_X = x + getPos_X();
                    fire_Y = y + getPos_Y();
                }

                x = getRand(20) - 10;
                int y_Range = 10 - absValue(x);
                y = getRand(1) == 0 ? y_Range : -y_Range; // 2*yrange give double of the range, then - the range give random + / - num

                fire_X = x + getPos_X();
                fire_Y = y + getPos_Y();
            }
            
            cout << "X: " << fire_X << " Y: " << fire_Y << endl << endl;

            Robot* shoot = Test.getRobot(fire_X, fire_Y);

            if(shoot != nullptr)
            {
                cout << getName() << " --Shoot--> " << shoot->getName() << endl;
                Test.clearPos(shoot);
                shoot->killed();
                killCount++;
                cout << "score " << killCount << endl << endl;
                // if (killCount >= 3) 
                // {
                //     upgradeToTerminator();
                // }
            
            }

            

            // Get Field Info
            // Kill if exist Robot
            cout << endl;
        }

        void altfire(Robot** robots, Battlefield &Test) 
        {
            int fire_X, fire_Y, x = 0, y = 0;

            while(fire_X >= Test.getrow() || fire_Y >= Test.getcol() || fire_X < 0 || fire_Y < 0 || (x == 0 && y == 0))
            {
                for (int i = 0; i < 3; i++)
                {
                    x = getRand(20) - 10;
                    int y_Range = 10 - absValue(x);
                    y = getRand(2 * y_Range + 1) - y_Range; // 2*yrange give double of the range, then - the range give random + / - num

                    fire_X = x + getPos_X();
                    fire_Y = y + getPos_Y();
                }

                x = getRand(20) - 10;
                int y_Range = 10 - absValue(x);
                y = getRand(1) == 0 ? y_Range : -y_Range; // 2*yrange give double of the range, then - the range give random + / - num

                fire_X = x + getPos_X();
                fire_Y = y + getPos_Y();
            }
            
            cout << "X: " << fire_X << " Y: " << fire_Y << endl << endl;

            Robot* shoot = Test.getRobot(fire_X, fire_Y);

            if(shoot != nullptr)
            {
                cout << getName() << " --Shoot--> " << shoot->getName() << endl << endl;
                Test.clearPos(shoot);
                shoot->killed();
                killCount++;
                cout << "score " << killCount << endl << endl;
                // if (killCount >= 3) 
                // {
                //     upgradeToTerminator();
                // }

            }

            

            // Get Field Info
            // Kill if exist Robot
            cout << endl;
        }

        bool ableToUpgrade()override{
            return false;
        }
    
        string getType() const {
            return "UltimateRobot";
        }

        void operation(Battlefield &Test)
        {
            // IF this robot alive, then do, else skip...
            if(getLive() == 0)
            {
                cout << "Robot " << getName() << " is Death, Skip This Turn" << endl << endl ; 
                return ;
            }
            
            Robot** pos = see(Test);
            // for(int i = 0 ; i < 9 ; i++){
            //     if(pos[i] != nullptr){
            //         cout << pos[i]->getName() << endl;
            //     }
            // }
            move(pos, Test);
            step(pos, Test);
            fire(pos, Test);
            altfire(pos, Test);
            
            // cout << "----" << Test.isEmptyPos(0,0);
        }
};


// void RobotCop::operation(Battlefield &Test)
// {
//     // IF this robot alive, then do, else skip...
//     if(getLive() == 0)
//     {
//         cout << "Robot " << getName() << " is Death, Skip This Turn" << endl << endl ; 
//         return ;
//     }
    
//     Robot** pos = see(Test);
//     // for(int i = 0 ; i < 9 ; i++){
//     //     if(pos[i] != nullptr){
//     //         cout << pos[i]->getName() << endl;
//     //     }
//     // }
//     move(pos, Test);
//     fire(pos, Test);
//     //upgrade(pos, Test);
    
//     // cout << "----" << Test.isEmptyPos(0,0);
// }

// void downcasting()
// {
//     RobotCop pobj;
//     Terminator pobj;

//     TerminatorRoboCop *cobj;

//     cobj = (TerminatorRoboCop *)&pobj;
//     cobj -> move(), step(), fire();

//     return
// }

// void upgrade()
// {
//     if (killCount == 3)
//     {}
// }


void upgrade1(Robot** robotList, int numRobots, Battlefield &Test) {
    for (int i = 0; i < numRobots; ++i) {
        if (robotList[i]->ableToUpgrade()) { 

            if(robotList[i]->getType() == "RoboTank"){}
            else if(robotList[i]->getType() == "Terminator"){}
            else if(robotList[i]->getType() == "TerminatorRoboCop"){}
            else if(robotList[i]->getType() == "BlueThunder"){}
            else if(robotList[i]->getType() == "Madbot"){}
            else if(robotList[i]->getType() == "RoboTank"){}
            else if(robotList[i]->getType() == "UltimateRobot"){}

            cout << robotList[i]->getName() << " is upgrading to TerminatorRoboCop!" << endl;

            // Create a new Terminator object
            TerminatorRoboCop* terminator = new TerminatorRoboCop(robotList[i]->getName(), robotList[i]->getPos_X(), robotList[i]->getPos_Y(), robotList[i]->getLive());

            delete robotList[i];
            cout << "Deleted RobotCop" << endl;

            // Replace the old RobotCop object with the new Terminator object in the robotList
            robotList[i] = terminator;
            cout << "RobotCop/Terminator Update To TerminatorRoboCop Sucess~" << endl;

            
            Test.updatePos(robotList[i], robotList[i]->getPos_X(), robotList[i]->getPos_Y());
        }
    }
}

int main() 
{
    /*
    // srand (time(0));

    // int field_X = 10;
    // int field_Y = 10;
	// Battlefield Test(field_X, field_Y);

    // int numRobots = 50;

    // cout << numRobots << endl;

    // Robot* robots[numRobots];

    // for (int i = 0; i < numRobots; i++) 
    // {
    //     int x = getRand(10) % field_X;
    //     int y = getRand(10) % field_Y;

    //     while(!Test.isEmptyPos(x, y))
    //     {
    //         x = getRand(10) % field_X;
    //         y = getRand(10) % field_Y;
    //     }

    //     robots[i] = new TerminatorRoboCop(to_string(i), x, y);
    //     Test.updatePos(robots[i]);
    //     cout << endl;
    // }

    // Test.display(robots, numRobots);


    // for (int j = 0; j < 10; j++) 
    // {
    //     for (int i = 0; i < numRobots; i++) 
    //     {
    //         // cout << "(" << robots[i]->getPos_X() << " , " << robots[i]->getPos_Y() << ")" << endl;
    //         robots[i]->operation(Test);
    //     }
    //     Test.display(robots, numRobots);
    //     cout << endl;
    // }

	// // RobotCop A("A", rand()%field_X,rand()%field_Y);
	// // RobotCop B("B", rand()%field_X,rand()%field_Y);

    // // Robot* robots[] = { &A, &B };
    // // int numRobots = sizeof(robots) / sizeof(robots[0]);

	// Test.display(robots, numRobots);

    // // TerminatorRoboCop A;
    // // A.see(0,0);

    // for(int i = 0; i < numRobots; i++) 
    // {
    //     delete robots[i];
    // }

    */

	// return 0;
    srand (time(0));

    ifstream file("robot_info.txt");

    try {
        if (!file.is_open())
            throw runtime_error("Something went wrong when reading the file");

    } catch (const runtime_error &error) {
        cout << error.what() << endl;
        return 1; // Exit if the file can't be opened
    }

    string temp, field_x, field_y, steps, robots, robotType, robotName, initialPos_X, initialPos_Y;

    // Read field dimensions
    while (temp[temp.size() - 1] != ':')
        file >> temp;
    file >> field_x >> field_y;

    // Read steps
    temp = field_y;
    while (temp[temp.size() - 1] != ':')
        file >> temp;
    file >> steps;

    // Read number of robots
    temp = steps;
    while (temp[temp.size() - 1] != ':')
        file >> temp;
    file >> robots;

    // Skip the rest of the line
   
    int field_X = stoi(field_x);
    int field_Y = stoi(field_y);
    Battlefield Test(field_X, field_Y);

    const int MAX_ROBOTS = 100; 
    Robot* robotList[MAX_ROBOTS];
    int numRobots = 0;

    int stepp = stoi(steps);

    while (file >> robotType >> robotName >> initialPos_X >> initialPos_Y) 
    {
        int x = (initialPos_X == "random") ? rand() % field_X : stoi(initialPos_X);
        int y = (initialPos_Y == "random") ? rand() % field_Y : stoi(initialPos_Y);

        while(!Test.isEmptyPos(x, y) && initialPos_X == "random" && initialPos_Y == "random"){
            x = rand() % field_X;
            y = rand() % field_Y;
        }


        if (numRobots >= MAX_ROBOTS) {
            cout << "Reached maximum number of robots" << endl;
            break;
        }

        if (robotType == "Madbot") 
        {
            robotList[numRobots] = new Madbot(string(1, robotName[0]), x, y, 1);
        } 
        else if (robotType == "RoboTank") 
        {
            robotList[numRobots] = new RoboTank(string(1, robotName[0]), x, y, 1);
        } 
        else if (robotType == "Terminator") 
        {
            robotList[numRobots] = new Terminator(string(1, robotName[0]), x, y, 1);
        } 
        else if (robotType == "BlueThunder") 
        {
            robotList[numRobots] = new BlueThunder(string(1, robotName[0]), x, y, 1);
        } 
        else if (robotType == "RoboCop") 
        {
            robotList[numRobots] = new RobotCop(string(1, robotName[0]), x, y, 1);
            // upgrade1(robotList, numRobots);
        } 
        else if (robotType == "TerminatorRoboCop") 
        {
            robotList[numRobots] = new TerminatorRoboCop(string(1, robotName[0]), x, y, 1);
        } 
        else if (robotType == "UltimateRobot") 
        {
            robotList[numRobots] = new UltimateRobot(string(1, robotName[0]), x, y, 1);
        } 
        else 
        {
            cout << "Unknown robot type: " << robotType << endl;
            continue;
        }
    
        Test.updatePos(robotList[numRobots]);
        numRobots++;
        cout << endl;
    }
    
    Test.display(robotList, numRobots);

    for (int j = 0; j < 5; j++) 
    {
        for (int i = 0; i < numRobots; i++) 
        {
            robotList[i]->operation(Test);
        }
        upgrade1(robotList, numRobots, Test);
        Test.display(robotList, numRobots);
        cout << endl;
        // Test.showPos();  //This function hjust for debugging
    }

    // // Clean up dynamically allocated robots
    // for (int i = 0; i < numRobots; ++i) {
    //     delete robotList[i];
    // }

    file.close();
    return 0;

}
