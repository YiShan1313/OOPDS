#include <iostream>
// inher, poly, basic robot, battlefield

using namespace std;

const int width = 20;
const int length = 20;

class Robot
{
    private:
        string name;
        int health;
        int def;
        int live;

    public:
        Robot(string n, int h, int d)
        {
            name = n;
            health = h;
            def = d;

        }

        void setName (string n)
        {
            name = n;
        }

        void setHealth (int h)
        {
            health = h;
        }

        void setDef (int d)
        {
            def = d;
        }

        string getName ()
        {
            return name;
        }

        int getDef()
        {
            return def;
        }

        bool getHealth()
        {
            return health > 0;
        }

        void takeDamage(int damage)
        {
            health -= damage;
        }

        virtual void attack(Robot& opponent) = 0;

};

class Movement
{

};

class View
{

};

class RoboCop  : public Robot
{
    public:
        //R1(){}

        RoboCop(string n, int h, int d) : Robot(n, h, d)
        {
            cout << getName() << " " << getHealth() << " " << getDef() << " is good" << endl;
        }

        void attack(Robot& opponent)
        {
            int damage = 10;
            opponent.takeDamage(damage);
            cout << getName() << " attacks " << opponent.getName() << " for " << damage << " damage." << endl;
        }
        
};

class Terminator : public Robot
{
    public:
        Terminator(string n, int h, int d) : Robot(n, h, d)
        {
            cout << getName() << " " << getHealth() << " " << getDef() << " is good" << endl;
        }

        void attack(Robot& opponent)
        {
            int damage = 1000;
            opponent.takeDamage(damage);
            cout << getName() << " attacks " << opponent.getName() << " for " << damage << " damage." << endl;
        }
};

class BlueThunder : public Robot
{
    public:
        BlueThunder(string n, int h, int d) : Robot(n, h, d)
        {
            cout << getName() << " " << getHealth() << " " << getDef() << " is good" << endl;
        }

        void attack(Robot& opponent)
        {
            int damage = 10;
            opponent.takeDamage(damage);
            cout << getName() << " attacks " << opponent.getName() << " for " << damage << " damage." << endl;
        }
};

class TerminatorRoboCop
{
    public:
        TerminatorRoboCop()
        {
            cout << "upgrade 1 is good" << endl;
        }
};

class Madbot
{
    public:
        Madbot()
        {
            cout << "upgrade 2 is good" << endl;
        }
};

class RoboTank
{
    public:
        RoboTank()
        {
            cout << "upgrade 3 is good" << endl;
        }
};

class UltimateRobot
{
    public:
        UltimateRobot()
        {
            cout << "upgrade 4 is good" << endl;
        }
};

class upgrade5
{
    public:
        upgrade5()
        {
            cout << "upgrade 5 is good" << endl;
        }
};

void battle(Robot& robot1, Robot& robot2, Robot& robot3) {
    while (robot1.getHealth() && robot2.getHealth() && robot3.getHealth()) {
        robot1.attack(robot2);
        robot2.attack(robot3);
        robot3.attack(robot1);
    }

    if (robot1.getHealth()) {
        cout << robot1.getName() << " wins the battle!" << endl;
    } else if (robot2.getHealth()) {
        cout << robot2.getName() << " wins the battle!" << endl;
    } else {
        cout << robot3.getName() << " wins the battle!" << endl;
    }
}

int main()
{

    RoboCop r1("Zeno", 100, 30);
    Terminator r2("Android 14", 100, 30);
    BlueThunder r3("Haha", 100, 30);
    TerminatorRoboCop();
    Madbot();
    RoboTank();
    UltimateRobot();
    upgrade5();


    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < length; j++)
        {
            cout << " * " ;
        }

        cout << " " << endl;
    }

    battle(r1, r2, r3);

    return 0;
}
