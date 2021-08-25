/*
NAME: Talike Bennett
HM5, Part 2, Header File (StackVector)
*/

#ifndef STACK_VECTOR
#define STACK_VECTOR

#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

template <typename someType>
class StackVector {

    public:

        StackVector(someType value1, someType value2, someType value3); //Value-accepting constructor
        bool Empty() const; //Empty()
        int Size() const; //Size()
        someType& Top(); //Top()
        void Push(someType value); //Push()
        void Pop(); //Pop()
        void Print() const; //Print()

    private:

        //Private data member(s)
        vector<someType> vec;

};

//Value-accepting constructor
template <typename someType>
StackVector<someType>::StackVector(someType value1, someType value2, someType value3) {

    cout << "Creating a new stack..." << endl;

    vector<someType> tempVec = {value1, value2, value3};

    for (unsigned int i = 0; i < tempVec.size(); i++) {

        vec.push_back(tempVec.at(i));

    }

    cout << endl;

}

//Empty(): Returns true if the stack is empty; returns false otherwise
template <typename someType>
bool StackVector<someType>::Empty() const {

    if (vec.size() <= 0) {

        return true;

    } else {

        return false;

    }

}

//Size(): Returns the size of the stack
template <typename someType>
int StackVector<someType>::Size() const {

    return vec.size();

}

//Top(): Returns the element at the top of the stack
template <typename someType>
someType& StackVector<someType>::Top() {

    return vec.at(vec.size() - 1);

}

//Push(): Adds a new element to the top of the stack
template <typename someType>
void StackVector<someType>::Push(someType value) {

    cout << "Pushing new value... (" << value << ")" << endl;
    vec.push_back(value);

}

//Pop(): Removes the element at the top of the stack
template <typename someType>
void StackVector<someType>::Pop() {

    cout << "Popping the top of the stack..." << endl;
    vec.pop_back();

}

//Print(): Prints the elements of the stack from top to bottom;
//         includes the visual structure of the stack as an
//         attempt to be *creative*.
template <typename someType>
void StackVector<someType>::Print() const {

    cout << "STACK:" << endl;

    if (this->Empty()) {

        cout << "|(empty)|" << endl;

    } else {

        for (int i = vec.size() - 1; i >= 0; i--) {

            cout << right << "|" << setw(7) << vec.at(i) << "|" << endl;

        }

    }

    cout << setfill('T') << setw(9) << "" << endl;
    cout << setfill(' ') << endl;

}

#endif
