#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class Robot 
{
private:
    string name;
    int live;
    int* pos_X; 
    int* pos_Y;

public:
    Robot() : pos_X(nullptr), pos_Y(nullptr), live(3) {}
    Robot(string n) : name(n), pos_X(nullptr), pos_Y(nullptr), live(3) {}

    void killed() {
        live = 0;
    }

    void setPosition(int* x, int* y) {
        pos_X = x;
        pos_Y = y;
    }

    void getPosition(int &x, int &y) {
        if (pos_X && pos_Y) {
            x = *pos_X;
            y = *pos_Y;
        }
    }

    string getName() const {
        return name;
    }
};

class Battlefield  : public Robot
{
private:
    int rows;
    int cols;
    string** grid;

public:
    Battlefield(int r, int c) {
        rows = r;  
        cols = c;  

        grid = new string*[rows];
        for (int i = 0; i < rows; ++i) {
            grid[i] = new string[cols];
            for (int j = 0; j < cols; ++j) {
                grid[i][j] = '.'; 
            }
        }
    }

    ~Battlefield() {
        for (int i = 0; i < rows; ++i) {
            delete[] grid[i];
        }
        delete[] grid;
    }

    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << grid[i][j] << ' ';
            }
            cout << endl;
        }
    }

    void placeRobot(int x, int y, string r_name)
    {
        if (x >= 0 && x < rows && y >= 0 && y < cols) {
            grid[x][y] = r_name;
        }
    }


    void removeRobot(int x, int y) {
        if (x >= 0 && x < rows && y >= 0 && y < cols) {
            grid[x][y] = '.';
        }
    }    

    int getrow() const {
        return rows;
    }

    int getcol() const {
        return cols;
    }

    string getPosition(int x, int y) const {
        if (x >= 0 && x < rows && y >= 0 && y < cols) {
            return grid[x][y];
        }
        return " ";
    }

    // void updatePosition(int oldX, int oldY, int newX, int newY, string r_name) {
    //     if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && grid[newX][newY] == ".") {
    //         removeRobot(oldX, oldY);
    //         placeRobot(newX, newY, r_name);
    //     }
    // }
};

class SeeingRobot : public Robot
{
private:
    Battlefield* battlefield;

public:
    SeeingRobot(string n, int* x, int* y, Battlefield* bf) : Robot(n), battlefield(bf) {
        setPosition(x, y);
    }

    void view(int x, int y) 
    {
        bool found = false;
        for (int i = x - 1; i <= x + 1; ++i) {
            for (int j = y - 1; j <= y + 1; ++j) {
                if (i == x && j == y) continue;
                if (i >= 0 && i < battlefield->getrow() && j >= 0 && j < battlefield->getcol() && battlefield->getPosition(i, j) != ".") {
                    cout << "Found a robot at (" << i << ", " << j << "): " << battlefield->getPosition(i, j) << endl;
                    found = true;
                }
            }
        }
        if (!found) 
        {
            cout << "No robots found around (" << x << ", " << y << ")" << endl;
        }
    }
};

class MovingRobot : public Robot 
{
public:
    MovingRobot(string n, int* x, int* y) : Robot(n) 
    {
        setPosition(x, y);
    }

    void move() {
        int oldX, oldY;
        getPosition(oldX, oldY);
        
        int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1},{-1,1},{-1,-1},{1,-1},{1,1}};
        srand(time(0));
        int* dir = directions[rand() % 8];
        
        int newX = oldX + dir[0];
        int newY = oldY + dir[1];

    }
};

int main() 
{
    Battlefield b(10,10);
    b.placeRobot(1,1,"Eric");
    b.display();
    return 0;
}
