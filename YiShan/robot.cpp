
#include <iostream>
// inher, poly, basic robot, battlefield

using namespace std;

const int width = 20;
const int length = 20;

int absValue(int a) {
    return (a < 0) ? -a : a;
}

class Robot {
  private:
	string name;
	int live;
	int pos_X, pos_Y;

  public:
	Robot() {}
	Robot(string n) { name = n; }

	virtual void see() = 0;
	virtual void fire() = 0;
	virtual void step() = 0;
	virtual void move() = 0;

	void killed() {
		live = 3;

		// if (live > 0) {
		// 	return live;
		// }
	}
};

class MovingRobot : public Robot {
  public:
	MovingRobot() {}
	virtual void move() = 0;
};

class ShootingRobot : public Robot {
  public:
	ShootingRobot() {}
	virtual void fire() = 0;
};

class SeeingRobot : public Robot {
  public:
	SeeingRobot() {}
	virtual void look() = 0 ;
};

class SteppingRobot : public Robot {
  public:
	SteppingRobot() {}
	virtual void step() = 0;
};

class RobotCop : public SeeingRobot, public MovingRobot, public ShootingRobot {
  bool enermyFound = false;
  
  public:
	RobotCop() { cout << "RobotCop Created" << endl; }

	~RobotCop() { cout << "~RobotCop Destroyed" << endl; }

	virtual void func() { cout << "Robocop" << endl; }

	void see(int x, int y){
		// This robot see its current position only, 再看要不要parameter
		// Move to no-robot position	Means return enermy position to avoid stepping it
		// Get Feild Info
	}

	void move(int x, int y){
		if (absValue(x) > 1 || absValue(y) > 1) 
			throw "X or Y value is > 1, Can only Move Neighbourhood";
	}

	void fire(int x, int y) {
		if (absValue(x) + absValue(y) > 10) 
			throw "X + Y value is > 10";
		
		// Get Feild Info
		// Kill if exist Robot
	}
};

/*
class R2 : virtual public Robot {
  public:
	R2() { cout << "test2" << endl; }

	~R2() { cout << "~test2" << endl; }

	virtual void func() { cout << "Terminator" << endl; }

	void step() {
		if (x *y = 9) {
		}
	}
};

class R3 : virtual public Robot {
  public:
	R3() { cout << "test2" << endl; }

	~R3() { cout << "~test2" << endl; }

	virtual void func() { cout << "Blue Thunder" << endl; }

	void fire() {}
};

class up1 : virtual public Robot {
  public:
	up1() { cout << "test3" << endl; }

	~up1() { cout << "~test3" << endl; }

	virtual void func() { cout << "TerminatorRoboCop" << endl; }

	void fire() {
		if (x + y = 10) {
			for (int i; i < 3; i++) {
			}
		}
	}

	void step() {
		if (x *y = 9) {
		}
	}
};

class up2 : virtual public Robot {
  public:
	up2() { cout << "test3" << endl; }

	~up2() { cout << "~test3" << endl; }

	virtual void func() { cout << "MadBot" << endl; }

	void fire() {}
};

class up3 : virtual public Robot {
  public:
	up3() { cout << "test3" << endl; }

	~up3() { cout << "~test3" << endl; }

	virtual void func() { cout << "RoboTank" << endl; }

	void fire() {}
};

class up4 : virtual public Robot {
  public:
	up4() { cout << "test3" << endl; }

	~up4() { cout << "~test3" << endl; }

	virtual void func() { cout << "UltimateRobot" << endl; }

	void fire() {}

	void step() {
		if (x *y = 9) {
		}
	}
};

*/

int main() { return 0; }
