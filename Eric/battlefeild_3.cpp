#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int absValue(int a) {
    return (a < 0) ? -a : a;
}

class Robot {
private:
    string name;
    int live;
    int pos_X, pos_Y;

public:
    Robot() : live(3), pos_X(0), pos_Y(0) {}  // Default constructor
    Robot(string n, int x, int y) : name(n), live(3), pos_X(x), pos_Y(y) {} // Parameterized constructor

    virtual void see() = 0;
    virtual void fire() = 0;
    virtual void step() = 0;
    virtual void move() = 0;

    int getPos_X() const {
        return pos_X;
    }
    int getPos_Y() const {
        return pos_Y;
    }

    void killed() {
        live = 0;
    }

    string getName() const {
        return name;
    }

    void setName(const string& n) {
        name = n;
    }

    void setPosition(int x, int y) {
        pos_X = x;
        pos_Y = y;
    }
};

class MovingRobot : virtual public Robot {
public:
    MovingRobot() : Robot() {}
    void see() override {};
    void fire() override {};
    void step() override {}
    void move() override {};
};

class ShootingRobot : virtual public Robot {
public:
    ShootingRobot() : Robot() {}
    void see() override {};
    void fire() override {};
    void step() override {}
    void move() override {};
};

class SeeingRobot : virtual public Robot {
public:
    SeeingRobot() : Robot() {}
    void see() override {};
    void fire() override {};
    void step() override {}
    void move() override {};
};

class SteppingRobot : virtual public Robot {
public:
    SteppingRobot() : Robot() {}
    void see() override {};
    void fire() override {};
    void step() override {}
    void move() override {};
};

class RobotCop : public SeeingRobot, public MovingRobot, public ShootingRobot {
    bool enemyFound = false;

public:
    RobotCop() {
        cout << "RobotCop Created" << endl;
    }

    RobotCop(string n, int x, int y) : Robot(n, x, y) {
        cout << "RobotCop Created" << endl;
    }

    ~RobotCop() {
        cout << "~RobotCop Destroyed" << endl;
    }

    void see() override {
        // Implementation of see method
    }

    void fire() override {
        // Implementation of fire method
    }

    void step() override {
        // Implementation of step method
    }

    void move() override {
        // Implementation of move method
    }

    void see(int x, int y) {
        // This robot see its current position only, 再看要不要parameter
        // Move to no-robot position	Means return enemy position to avoid stepping it
        // Get Field Info
    }

    void move(int x, int y) {
        if (abs(x) > 1 || abs(y) > 1)
            throw "X or Y value is > 1, Can only Move Neighbourhood";
    }

    void fire(int x, int y) {
        if (abs(x) + abs(y) > 10)
            throw "X + Y value is > 10";

        // Get Field Info
        // Kill if exist Robot
    }
};


class Battlefield {
  private:
	int rows;
	int cols;

  public:
	Battlefield(int r, int c) {
		rows = r;
		cols = c;
	}

	~Battlefield() {
		cout << "Battle Feild Destroyed" << endl;
	}

	void display(Robot* Robots[], int numRobots) const {
        int pos_x[numRobots];
        int pos_y[numRobots];

        for(int i = 0; i < numRobots ; i++){
            pos_x[i] = Robots[i]->getPos_X();
            pos_y[i] = Robots[i]->getPos_Y();
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                bool setted = false;

                for(int u = 0; u < numRobots ; u++){
                    if(i == pos_x[u] && j == pos_y[u]){
                        cout << " " << Robots[u]->getName() << " ";
                        setted = true;
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

	int getrow() const { return rows; }

	int getcol() const { return cols; }

	// string getPosition(int x, int y) const {
		// if (x >= 0 && x < rows && y >= 0 && y < cols) {
		// 	return grid[x][y];
		// }
		// return " ";
	// }

	// void updatePosition(int oldX, int oldY, int newX, int newY, string
	// r_name) {
	//     if (newX >= 0 && newX < rows && newY >= 0 && newY < cols &&
	//     grid[newX][newY] == ".") {
	//         removeRobot(oldX, oldY);
	//         placeRobot(newX, newY, r_name);
	//     }
	// }
};


int main() {
	RobotCop A("A", 0,0);
	RobotCop B("B", 1,1);
	Battlefield Test(10, 10);

    Robot* robots[] = { &A, &B };
    int numRobots = sizeof(robots) / sizeof(robots[0]);

	Test.display(robots, numRobots);
	return 0;
}
