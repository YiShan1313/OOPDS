#include<iostream>
using namespace std;

class Battlefield 
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

    void removeRobot(int x, int y) 
    {
        if (x >= 0 && x < rows && y >= 0 && y < cols) 
        {
            grid[x][y] = '.';
        }
        
    }    

    int getrow()
    {
        return rows;
    }

    int getcol()
    {
        return cols;
    }

    string getPosition (int x, int y) const {
        if (x >= 0 && x < rows && y >= 0 && y < cols) {
            return grid[x][y];
        }
        return " ";
    }
    bool view(int x, int y) {
        for (int i = x - 1; i <= x + 1; ++i) {
            for (int j = y - 1; j <= y + 1; ++j)
            {
                if (i == x && j == y) continue; 
                if (i >= 0 && i < getrow() && j >= 0 && j < getcol() && getPosition(i, j) != ".") 
                {
                    return true; 
                    cout << "have a robot";
                }
            }
        }
        return false; 
    }
};

// class SeeingRobot : public Battlefield
// {
//     public:
//     bool view(int x, int y) {
//         for (int i = x - 1; i <= x + 1; ++i) {
//             for (int j = y - 1; j <= y + 1; ++j) {
//                 if (i == x && j == y) continue; 
//                 if (i >= 0 && i < getrow() && j >= 0 && j < getcol() && getPosition(i, j) != ".") {
//                     return true; 
//                 cout << "a robot";
//                 }
//             }
//         }
//         return false; 
//     }
//     SeeingRobot(int x,int y):Battlefield(x,y){}
// };

class MovingRobot
{
    public:
    void move(){}
};

int main()
{   
    Battlefield map (20,60);
    map.placeRobot(1,29,"Banny");
    map.placeRobot(13,34,"WW");
    map.placeRobot(13,33,"Y");
    map.removeRobot(1,29);
    map.display();
    map.view(13,34);

    return 0;
}