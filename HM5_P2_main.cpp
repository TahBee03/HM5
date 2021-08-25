/*
NAME: Talike Bennett
HM5, Part 2, Main File
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include "HM5_P2_Bennett_23778852_StackVector.hpp"
using namespace std;

int main() {

	srand(time(0)); //Assigns a new seed every time the program is ran.

	cout << "TEST CASE 1: Pop() Empties Stack" << endl;
    StackVector<int> sv1(3, 2, 1); //Stack of integers.

    sv1.Print();

    sv1.Push(33);
    sv1.Push(582);
    cout << endl;

    sv1.Print();

    while (sv1.Size() > 0) { //Removes all of the elements of the stack.

    	sv1.Pop();

    }

    cout << endl;

    sv1.Print();

    cout << "EMPTY CHECK" << endl;
    if (sv1.Empty()) {

        cout << "Your stack is empty!" << endl;

    } else {

        cout << "Your stack has " << sv1.Size() << " elements." << endl;

    }

    cout << setfill('*') << setw(50) << "" << setfill(' ') << endl;

    cout << "TEST CASE 2: Pop() Does Not Empty Stack" << endl;
    StackVector<string> sv2("apples", "jet", "box"); //Stack of strings

    sv2.Print();

    sv2.Push("pencil");
    sv2.Push("grape");
    cout << endl;

    sv2.Print();

    for (int i = (rand() % (sv2.Size() - 1)) + 1; i > 0; i--) { //Removes a different number of elements each time the program is ran.
                                                                //Range: [1, sv2.Size() - 1]
                                                                //Attempt to be *creative*.

    	sv2.Pop();

    }

    cout << endl;

    sv2.Print();

    cout << "EMPTY CHECK" << endl;
    if (sv2.Empty()) {

        cout << "Your stack is empty!" << endl;

    } else {

        cout << "Your stack has " << sv2.Size() << " elements." << endl;

    }

    cout << endl;
    cout << "Top of Stack: " << sv2.Top() << endl;

	return 0;

}
