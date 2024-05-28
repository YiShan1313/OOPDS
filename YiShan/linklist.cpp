#include <iostream>
#include <string>
using namespace std;

struct Turn {
	int turns;
	char *log;
	Turn *next;
};

Turn *find(Turn *turn_ptr, int _turns) {
	while (turn_ptr->turns != _turns && turn_ptr->next != nullptr) {
		turn_ptr = turn_ptr->next;
	}

	return turn_ptr;
}

Turn *pointToEnd(Turn *turn_ptr) {
	Turn *temp = turn_ptr;
	while (temp->next != nullptr)
		temp = temp->next;
	return temp;
}

Turn* push_front(Turn *turn_ptr, int _turns, char *_log){
    Turn *newptr = new Turn;
    newptr->turns = _turns;
    newptr->log = _log;

    newptr->next = turn_ptr;
    return newptr;
}

void push_back(Turn *turn_ptr, int _turns, char *_log){
    Turn *temp = turn_ptr;
    temp = pointToEnd(temp);
    Turn *newptr = new Turn;
    newptr->turns = _turns;
    newptr->log = _log;
    newptr->next = nullptr;
    //link
    temp->next = newptr;
}

void print(Turn *turn_ptr){
    while(turn_ptr != nullptr){
        cout << turn_ptr->turns << endl;
        cout << turn_ptr->log << endl;
        turn_ptr = turn_ptr->next;
    }
}

int main() {
    Turn* Start;
    Turn* newptr;
    newptr = new Turn;

    // First Turn
    newptr->turns = 1;
    newptr->log = "Test1\n OSKdojdaso\nadsada";
    newptr->next = nullptr;

    Start = newptr;

    // Second Turn
    Start = push_front(Start, 2, "Test2");
    // Thrid Turn
    Start = push_front(Start, 3, "Test3");
    // Adding to backward
    push_back(Start, 4, "Test4");

    //Adding to a position
    Turn* pos = find(Start, 2);
    newptr = new Turn;
    newptr->turns = 99;
    newptr->log = "Test99";
    newptr->next = pos->next;
    pos->next = newptr;

    // Printing result
    print(Start);

    return 0;
}