/*
NAME: Talike Bennett
HM5, Part 1, Header File (CheckedArray)
*/

#ifndef CHECKED_ARRAY
#define CHECKED_ARRAY

#include <iostream>
#include <stdexcept>
#include "HM5_P1_Bennett_23778852_ArrayOutOfRange.hpp"
using namespace std;

template <typename someType>
class CheckedArray {

    public:

        class ArrayOutOfRangeError { //ArrayOutOfRangeError exception class

            public:

                string GetMessage() const { return this->message; } //Getter

            private:

                string message = "ERROR: Accessing array out of range."; //Error message

        };

        static const int arraySize = 5;  //Set as static so it can be used to set array size.

        CheckedArray(); //Default constructor
        CheckedArray(someType element1, someType element2, someType element3, //Value-accepting constructor
                     someType element4, someType element5);

        void PrintInfo() const; //Print function
        someType& operator[](int index); //[] operator function

    private:

        //Private data member(s)
        someType elementList[arraySize];

};

//Default constructor
template <typename someType>
CheckedArray<someType>::CheckedArray() {

    for (int i = 0; i < arraySize; i++) {

        this->elementList[i] = 0;

    }

}

//Value accepting constructor
template <typename someType>
CheckedArray<someType>::CheckedArray(someType element1, someType element2, someType element3,
                                     someType element4, someType element5) {

    someType elementList[] = {element1, element2, element3, element4, element5};

    for (int i = 0; i < arraySize; i++) {

        this->elementList[i] = elementList[i];

    }

}

//Print function
template <typename someType>
void CheckedArray<someType>::PrintInfo() const {

    for (int i = 0; i < arraySize; i++) {

        cout << this->elementList[i] << " ";

    }

    cout << endl;

}

//[] operator function
template <typename someType>
someType& CheckedArray<someType>::operator[](int index) {

    if (index < 0 || index >= arraySize) { //Throws one of the following exceptions if illegal index is detected.

        //NOTE: Uncomment either throw statement and the corresponding catch blocks for Test Case 1.
        //throw ArrayOutOfRangeError(); //Throws an ArrayOutOfRangeError-type exception.
                                        //UNCOMMENT FOR TEST CASE 2.
        //throw out_of_range("ERROR: Accessing array out of range."); //Throws an out_of_range-type exception.
                                                                      //UNCOMMENT FOR TEST CASE 3.
        throw ArrayOutOfRange("ERROR: Accessing array out of range.", arraySize, index); //Throws an ArrayOutRange-type exception.
                                                                                         //UNCOMMENT FOR TEST CASE 4.

    }

    return elementList[index];

}

#endif
