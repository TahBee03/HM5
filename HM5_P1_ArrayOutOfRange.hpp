/*
NAME: Talike Bennett
HM5, Part 1, Header File (ArrayOutOfRange)
*/

#ifndef ARRAY_OUT_OF_RANGE
#define ARRAY_OUT_OF_RANGE

#include <iostream>
#include <stdexcept>
#include <string>
#include <cstring>
using namespace std;

class ArrayOutOfRange : public out_of_range { //ArrayOutOfRange inherits all the attributes of out_of_range.

    public:

        ArrayOutOfRange(const string& errorMsg, int arraySize, int illegalIndex); //Value-accepting constructor
        const char* what() const noexcept; //what() function (overridden)

    protected:

        //Protected data member(s)
        int arraySize;
        int illegalIndex;

};

//Value-accepting constructor
ArrayOutOfRange::ArrayOutOfRange(const string& errorMsg, int arraySize, int illegalIndex) : out_of_range(errorMsg) {

    this->arraySize = arraySize;
    this->illegalIndex = illegalIndex;

}

//what() function (overridden)
const char* ArrayOutOfRange::what() const noexcept {

    //NOTE: to_string() converts a number to a string
    //      c_str() converts a string to a C-string

    static string whatString = out_of_range::what(); //Copies error message of out_of_range into a string.

    //Next 5 Lines: The illegal index and array size are converted to strings,
    //              and are then appended to to original error message.
    whatString.append(" (Attempted Index: ");
    whatString.append(to_string(illegalIndex));
    whatString.append(", Array Size: ");
    whatString.append(to_string(arraySize));
    whatString.append(")");

    return whatString.c_str(); //Returns entire error message as a C-string

}

#endif
