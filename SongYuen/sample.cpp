#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
using namespace std;

static const int row = 20;
static const int col = 20;

class Robot
{
    private:
        string name;
        int live;

    public:
        Robot()
        {}

        Robot(string n)
        {   
            name = n;
        }

        virtual void see() = 0;
        virtual void fire() = 0;
        virtual void step() = 0;
        virtual void move() = 0;
};

class field
{
    protected:
        char grid[row][col];

    public:
        field()
        {
            for (int i = 0; i < row; i++)
            {

                for (int j = 0; j < col; j++)
                {
                    grid[i][j] = ' ';
                }
            }
        }

        void place(string name, int posx, int posy)
        {
            if (posx >= 0 && posx < row && posy >= 0 && posy < col && !name.empty())
            {
                char test = name[0];
                grid[posx][posy] = test;
            }
        }

        void display()
        {
            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    if (grid[i][j] == ' ')
                    {
                        cout << " * ";
                    }

                    else
                    {
                        cout << " " << grid[i][j] << " ";
                    }
                }
                cout << endl;
            }
        }
};

class movement : public field
{
    public:
        void move(string name, int &moves)
        {
            int posx = -1;
            int posy = -1;

            for(int i = 0; i < row; i++)
            {
                for(int j = 0; j < col; j++)
                {
                    if (grid[i][j] == name[0])
                    {
                        posx = i;
                        posy = j;
                        break;
                    }
                }

                if(posx != -1 && posy != -1)
                {
                    break;
                }
            }
        

        if (posx != -1 && posy != -1)
        {
            int direct = rand() % 8;

            switch (direct)
            {
                case 0:
                    if (posx > 0)
                    {
                        grid[posx][posy] = ' ';
                        grid[posx - 1][posy] = name[0];
                    }
                    break;
                case 1:
                    if (posx > 0)
                    {
                        grid[posx][posy] = ' ';
                        grid[posx][posy - 1] = name[0];
                    }
                    break;
                case 2:
                    if (posx > 0)
                    {
                        grid[posx][posy] = ' ';
                        grid[posx + 1][posy] = name[0];
                    }
                    break;
                case 3:
                    if (posx > 0)
                    {
                        grid[posx][posy] = ' ';
                        grid[posx][posy + 1] = name[0];
                    }
                    break;
                case 4:
                    if (posx > 0)
                    {
                        grid[posx][posy] = ' ';
                        grid[posx - 1][posy - 1] = name[0];
                    }
                    break;
                case 5:
                    if (posx > 0)
                    {
                        grid[posx][posy] = ' ';
                        grid[posx + 1][posy + 1] = name[0];
                    }
                    break;
                case 6:
                    if (posx > 0)
                    {
                        grid[posx][posy] = ' ';
                        grid[posx + 1][posy - 1] = name[0];
                    }
                    break;
                case 7:
                    if (posx > 0)
                    {
                        grid[posx][posy] = ' ';
                        grid[posx - 1][posy + 1] = name[0];
                    }
                    break;
                default:
                    break;
            }

            if(posx )

            moves--;
        }

        }
};

class seeingRobot : public Robot
{
    public:
        virtual void see()
        {

        }
};

class shootingRobot : public Robot
{
    public:
        virtual void fire()
        {

        }
};

class steppingRobot : public Robot
{
    public:
        virtual void step()
        {

        }
};

class robotCop : public seeingRobot, public movement, public shootingRobot
{
    public:
        robotCop()
        {
            cout << "test1" << endl;
        }

        ~robotCop()
        {
            cout << "~test1" << endl;
        }

        virtual void func()
        {
            cout << "Robocop" << endl;
        }

        void see(int x, int y)
        {
            // This robot see its current position only, 再看要不要parameter
            // Move to no-robot position	Means return enermy position to avoid stepping it
            // Get Feild Info
        }

        void move(int x, int y)
        {
            // if (absValue(x) > 1 || absValue(y) > 1) 
            //     throw "X or Y value is > 1, Can only Move Neighbourhood";
        }

        void fire(int x, int y) 
        {
            // if (absValue(x) + absValue(y) > 10) 
            //     throw "X + Y value is > 10";
            
            // Get Feild Info
            // Kill if exist Robot
        }

};

class terminator :  virtual public Robot
{
    public:
        terminator()
        {
            cout << "test2" << endl;
        }

        ~terminator()
        {
            cout << "~test2" << endl;
        }

        virtual void func()
        {
            cout << "Terminator" << endl;
        }

        void see(int x, int y)
        {
            // This robot see its current position only, 再看要不要parameter
            // Move to no-robot position	Means return enermy position to avoid stepping it
            // Get Feild Info
        }

        void move(int x, int y)
        {
            // if (absValue(x) > 1 || absValue(y) > 1) 
            //     throw "X or Y value is > 1, Can only Move Neighbourhood";
        }

        void step()
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if("any robot beside itself")
                    {
                        
                    }
                }
            }
        }

};

class blueThunder :  virtual public Robot
{
    public:
        blueThunder()
        {
            cout << "test2" << endl;
        }

        ~blueThunder()
        {
            cout << "~test2" << endl;
        }

        virtual void func()
        {
            cout << "Blue Thunder" << endl;
        }

        void fire(int x, int y) 
        {
            // int targetX = x + dx[currentDirection];
            // int targetY = y + dy[currentDirection];

            // if (isValid(targetX, targetY) && grid[targetX][targetY] == 'R') {
            //     cout << "Firing at (" << targetX << ", " << targetY << ") - Hit!" << endl;
            //     grid[targetX][targetY] = '.'; // Assume '.' represents an empty cell
            //     shotCount++;
            // } else {
            //     cout << "Firing at (" << targetX << ", " << targetY << ") - Miss" << endl;
            // }
        }


};

class terminatorRoboCop : virtual public Robot
{
    public: 
        terminatorRoboCop()
        {
            cout << "test3" << endl;
        }

        ~terminatorRoboCop()
        {
            cout << "~test3" << endl;
        }

        virtual void func()
        {
            cout << "TerminatorRoboCop" << endl;
        }

        void see(int x, int y)
        {
            // This robot see its current position only, 再看要不要parameter
            // Move to no-robot position	Means return enermy position to avoid stepping it
            // Get Feild Info
        }

        void move(int x, int y)
        {
            // if (absValue(x) > 1 || absValue(y) > 1) 
            //     throw "X or Y value is > 1, Can only Move Neighbourhood";
        }

        void fire(int x, int y) 
        {
            // if (absValue(x) * absValue(y) > 9) 
            //     throw "X + Y value is > 9";
            
            // Get Feild Info
            // Kill if exist Robot
        }

        void step()
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if("any robot beside itself")
                    {
                        
                    }
                }
            }
        }


};

class madBot : virtual public Robot
{
    public: 
        madBot()
        {
            cout << "test3" << endl;
        }

        ~madBot()
        {
            cout << "~test3" << endl;
        }

        virtual void func()
        {
            cout << "MadBot" << endl;
        }

        void see(int x, int y)
        {
            // This robot see its current position only, 再看要不要parameter
            // Move to no-robot position	Means return enermy position to avoid stepping it
            // Get Feild Info
        }

        void fire(int x, int y) 
        {
            // int targetX = x + dx;
            // int targetY = y + dy;

            // if (isValid(targetX, targetY) && grid[targetX][targetY] == 'R') {
            //     cout << "Firing at (" << targetX << ", " << targetY << ") - Hit!" << endl;
            //     grid[targetX][targetY] = '.'; // Assume '.' represents an empty cell
            //     shotCount++;
            // } else {
            //     cout << "Firing at (" << targetX << ", " << targetY << ") - Miss" << endl;
            // }
        }


};

class roboTank : virtual public Robot
{
    public: 
        roboTank()
        {
            cout << "test3" << endl;
        }

        ~roboTank()
        {
            cout << "~test3" << endl;
        }

        virtual void func()
        {
            cout << "RoboTank" << endl;
        }

        void see(int x, int y)
        {
            // This robot see its current position only, 再看要不要parameter
            // Move to no-robot position	Means return enermy position to avoid stepping it
            // Get Feild Info
        }


        void fire(int x, int y) 
        {
            //randomly fire
        }


};

class ultimateRobot : virtual public Robot
{
    public: 
        ultimateRobot()
        {
            cout << "test3" << endl;
        }

        ~ultimateRobot()
        {
            cout << "~test3" << endl;
        }

        virtual void func()
        {
            cout << "UltimateRobot" << endl;
        }

        void see(int x, int y)
        {
            // This robot see its current position only, 再看要不要parameter
            // Move to no-robot position	Means return enermy position to avoid stepping it
            // Get Feild Info
        }

        void move(int x, int y)
        {
            // if (absValue(x) > 1 || absValue(y) > 1) 
            //     throw "X or Y value is > 1, Can only Move Neighbourhood";
        }

        void fire(int x, int y) 
        {
            // if (absValue(x) * absValue(y) > 9) 
            //     throw "X + Y value is > 9";
            
            // Get Feild Info
            // Kill if exist Robot
        }

        void step()
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if("any robot beside itself")
                    {
                        
                    }
                }
            }
        }        


};

int main()
{
    srand (time(0));

    movement test;
    test.place("zeno", 5, 5);
    test.place("ali", 7, 5);
    test.display();
    cout << endl;

    int zeno_moves = 20;
    int ali_moves = 20;

    while (zeno_moves > 0 || ali_moves > 0)
    {
        if (zeno_moves > 0)
        {
            test.move("zeno", zeno_moves);
        }

        if (ali_moves > 0)
        {
            test.move("ali", ali_moves);
        }

        test.display();
        cout << endl;
    }

    return 0;
}

