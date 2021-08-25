/*
NAME: Talike Bennett
HM5, Part 1, Main File
*/

#include <iostream>
#include <iomanip>
#include "HM5_P1_Bennett_23778852_CheckedArray.hpp"
#include "HM5_P1_Bennett_23778852_ArrayOutOfRange.hpp"
using namespace std;

int main() {

    CheckedArray<int> array1; //Array of integers
    CheckedArray<double> array2(0, 0.5, 1, 1.5, 2); //Array of floating-point numbers
    CheckedArray<string> array3("This", "is", "a", "string", "array."); //Array of strings

    //cout << "TEST CASE 1: No Error" << endl;                       //UNCOMMENT FOR TEST CASE 1.
    //cout << "TEST CASE 2: ArrayOutOfRangeError Exception" << endl; //UNCOMMENT FOR TEST CASE 2.
    //cout << "TEST CASE 3: out_of_range Exception" << endl;         //UNCOMMENT FOR TEST CASE 3.
    cout << "TEST CASE 4: ArrayOutOfRange Exception" << endl;      //UNCOMMENT FOR TEST CASE 4.
    cout << setfill('*') << setw(40) << "" << setfill(' ') << endl;

    cout << "INITIAL VALUES" << endl;
    cout << "Array 1: ";
    array1.PrintInfo();
    cout << "Array 2: ";
    array2.PrintInfo();
    cout << "Array 3: ";
    array3.PrintInfo();

    cout << endl;

    try { //Holds code that may cause an error.

    	cout << "CHANGES" << endl;
    	cout << "array1[0] = 55" << endl;
        cout << "array2[4] += array2[2]" << endl;
        cout << "array3[8] = \"array?\"" << endl; //CHANGE TO VALID INDEX FOR TEST CASE 1.
        cout << endl;

        array1[0] = 55;
        array2[4] += array2[2];
        array3[8] = "array?"; //Accessing illegal array index. CHANGE TO VALID INDEX FOR TEST CASE 1.

    }
   // catch(CheckedArray<int>::ArrayOutOfRangeError error) { //Catches an ArrayOutOfRangeError-type exception (for int CheckedArray).
                                                             //UNCOMMENT FOR TEST CASE 2.

   //     cout << error.GetMessage() << endl << endl;

   // }
   // catch(CheckedArray<string>::ArrayOutOfRangeError error) { //Catches an ArrayOutOfRangeError-type exception (for string CheckedArray).
                                                                //UNCOMMENT FOR TEST CASE 2.

   //     cout << error.GetMessage() << endl << endl;

   // }
   // catch(CheckedArray<double>::ArrayOutOfRangeError error) { //Catches an ArrayOutOfRangeError-type exception (for double CheckedArray).
                                                                //UNCOMMENT FOR TEST CASE 2.

   //     cout << error.GetMessage() << endl << endl;

   // }
   // catch(out_of_range& error) { //Catches an out_of_range-type exception. UNCOMMENT FOR TEST CASE 3.

   //     cout << error.what() << endl << endl;

   // }
    catch(ArrayOutOfRange& error) { //Catches an ArrayOutOfRange-type exception. UNCOMMENT FOR TEST CASE 4.

        cout << error.what() << endl << endl;

    }

    cout << "UPDATED VALUES" << endl;
    cout << "Array 1: ";
    array1.PrintInfo();
    cout << "Array 2: ";
    array2.PrintInfo();
    cout << "Array 3: ";
    array3.PrintInfo();

	return 0;

}
