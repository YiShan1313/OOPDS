#include <iostream>
// inher, poly, basic robot, battlefield

using namespace std;

const int width = 20;
const int length = 20;

class Robot
{
    private:
        string name;
        int live;

    public:
        Robot(string n)
        {   
            name = n;
        }

        virtual void see() = 0;
        virtual void fire() = 0;
        virtual void step() = 0;
        virtual void move() = 0;

        void killed()
        {
            live = 3;

            if (live > 0)
            {
                return live;
            }
        }
};

class movingRobot : public Robot
{
    public:
};

class shootingRobot : public Robot
{
    public:
};

class seeingRobot : public Robot
{
    public:
};

class steppingRobot : public Robot
{
    public:
};

class R1 : public seeingRobot : public movingRobot : public shootingRobot
{
    public:
        R1()
        {
            cout << "test1" << endl;
        }

        ~R1()
        {
            cout << "~test1" << endl;
        }

        virtual void func()
        {
            cout << "Robocop" << endl;
        }

        void fire()
        {
            if (x + y =10)
            {   
                for (int i; i < 3; i++)
                {
                    
                }
            }
        }

};

class R2 :  virtual public Robot
{
    public:
        R2()
        {
            cout << "test2" << endl;
        }

        ~R2()
        {
            cout << "~test2" << endl;
        }

        virtual void func()
        {
            cout << "Terminator" << endl;
        }

        void step()
        {
            if (x * y = 9)
            {

            }
        }
};

class R3 :  virtual public Robot
{
    public:
        R3()
        {
            cout << "test2" << endl;
        }

        ~R3()
        {
            cout << "~test2" << endl;
        }

        virtual void func()
        {
            cout << "Blue Thunder" << endl;
        }

        void fire()
        {

        }
};

class up1 : virtual public Robot
{
    public: 
        up1()
        {
            cout << "test3" << endl;
        }

        ~up1()
        {
            cout << "~test3" << endl;
        }

        virtual void func()
        {
            cout << "TerminatorRoboCop" << endl;
        }

        void fire()
        {
            if (x + y = 10)
            {
                for (int i; i < 3 ; i++)
                {

                }
            }
        }

        void step()
        {
            if (x * y = 9)
            {

            }
        }
};

class up2 : virtual public Robot
{
    public: 
        up2()
        {
            cout << "test3" << endl;
        }

        ~up2()
        {
            cout << "~test3" << endl;
        }

        virtual void func()
        {
            cout << "MadBot" << endl;
        }

        void fire()
        {
            
        }
};

class up3 : virtual public Robot
{
    public: 
        up3()
        {
            cout << "test3" << endl;
        }

        ~up3()
        {
            cout << "~test3" << endl;
        }

        virtual void func()
        {
            cout << "RoboTank" << endl;
        }

        void fire()
        {

        }
};

class up4 : virtual public Robot
{
    public: 
        up4()
        {
            cout << "test3" << endl;
        }

        ~up4()
        {
            cout << "~test3" << endl;
        }

        virtual void func()
        {
            cout << "UltimateRobot" << endl;
        }

        void fire()
        {

        }

        void step()
        {
            if (x * y = 9)
            {

            }
        }
};

int main()
{
    return 0;
}
