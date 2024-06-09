#include "Battlefield.h"
#include "Robot.h"

Battlefield::Battlefield(int r, int c) {
    cout << "Battle Field Created" << endl;
    rows = r;
    cols = c;

    grid = new Robot**[rows];

    for (int i = 0; i < rows; ++i) {
        grid[i] = new Robot*[cols];
    }

    for(int i = 0 ; i < rows ; i++){
        for(int j = 0 ; j < rows ; j++){
            grid[i][j] = nullptr;
        }
    }
}

Battlefield::~Battlefield() {
    cout << "Battle Field Destroyed" << endl;
}

void Battlefield::display(Robot* Robots[], int numRobots) const {
    int pos_x[numRobots];
    int pos_y[numRobots];

    for(int i = 0; i < numRobots ; i++){
        pos_x[i] = Robots[i]->getPos_X();
        pos_y[i] = Robots[i]->getPos_Y();
    }

    cout << "   " ;
    for (int j = 0; j < cols; ++j) 
        cout << j << "  " ;
    cout << endl ;

    for (int i = 0; i < rows; ++i) {
        cout << i << " " ;
        for (int j = 0; j < cols; ++j) {
            bool setted = false;

            for(int u = 0; u < numRobots ; u++){
                if(j == pos_x[u] && i == pos_y[u]){
                    cout << "" << Robots[u]->getName() << " ";
                    setted = true;
                    break;
                }
            }

            if(!setted)
                cout << " * ";
            else
                setted = false;

        }
        cout << endl;
    } 
}

void Battlefield::updatePos(Robot* const robot,int prev_X, int prev_Y){
    if(prev_X != -1 || prev_Y != -1)
        grid[prev_X][prev_Y] = nullptr; 

    int x = robot->getPos_X();
    int y = robot->getPos_Y();
    grid[x][y] = robot; 
}

void Battlefield::clearPos(Robot* const robot){
    int x = robot->getPos_X();
    int y = robot->getPos_Y();
    grid[x][y] = nullptr; 
}

bool Battlefield::isEmptyPos(int x, int y)const{
    if(grid[x][y] != nullptr){
        cout << "Dectected" << endl;
        return false;
    }
    else    
        return true;
}

Robot* Battlefield::getRobot(int x, int y)const{
    if(x < getrow() && y < getcol())
        return grid[x][y];
    else
        return nullptr;
}