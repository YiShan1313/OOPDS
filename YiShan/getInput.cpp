#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ifstream file("input.txt");

    try{
        if(!file.is_open())
            throw "Something Wrong When Read File";

    }catch(const char* error){
        cout << error << endl;
    }

    string temp, feild_x, feild_y, steps, robots, robotType, robotName, initialPos_X, initialPos_Y;
    // getline(file, feild);
    // getline(file, steps);
    // getline(file, robots);

    while(temp[temp.size()-1] != ':')
        file >> temp;

    file >> feild_x >> feild_y;
    temp = feild_y;

    while(temp[temp.size()-1] != ':')
        file >> temp;

    file >> steps;
    temp = steps;

    while(temp[temp.size()-1] != ':')
        file >> temp;

    file >> robots;

    while(file >> robotType){
        file >> robotName >> initialPos_X >> initialPos_Y;
        cout << robotType << " " << robotName << " " << initialPos_X << " " << initialPos_Y << endl ;
        // GenerateBot(robotType, robotName, initialPos_X, initialPos_Y)
    }

    cout << feild_x << endl;
    cout << feild_y << endl;
    cout << steps << endl;
    cout << robots << endl;
}