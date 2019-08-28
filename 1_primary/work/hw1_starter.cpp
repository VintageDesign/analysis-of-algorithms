
#include <iostream>
#include <iomanip>
#include <time.h>
#include <vector>
#include <chrono>

#include "quickSort.h"
using namespace std;


/******************************************************
Template function for running correctness tests
GRADING: CORRECTNESS TESTS
******************************************************/
void correctness() {
    vector<int> test1 = { 2,1 };
    vector<int> test2 = { 1, 3, 2 };
    vector<int> test3 = { 2, 2, 1, 3, 5, 4, 8, 0 };
    vector<int> test4; //TODO fill in with 9 random values

    cout << "Test 1: Basic sort with 2 elements" << endl;
    cout << "Original: 2, 1" << endl;
    cout << "Quick Result: ";
    //TODO test, and display result
    vector<int> quickSortResult = quickSort(test1, 0, 1);

    for (int val : quickSortResult)
    {
       cout << val << " ";
    }
    cout << endl;
    cout << "Heap Result: ";
    //TODO test, and display result

    cout << endl;

    cout << "Test 2: Basic sort with 3 elements" << endl;
    cout << "Original: 1, 3, 2" << endl;
    cout << "Quick Result: ";
    //TODO test, and display result
    cout << "Heap Result: ";

    cout << endl;

    cout << "Test 3: Basic sort with even # of elements" << endl;
    cout << "Original: 2, 2, 1, 3, 5, 4, 8, 0 " << endl;
    cout << "Quick Result: ";
    //TODO test, and display result
    cout << "Heap Result: ";

    cout << endl;

    cout << "Test 4: Basic sort with odd # of elements" << endl;
    cout << "Original: "  << endl; //TODO print 9 random values
    cout << "Quick Result: ";
    //TODO test, and display result...TIP you can write a generic test if you check A[i+1] > A[i]
    cout << "Heap Result: ";

}



int main() {
    char choice = 'c';
    vector<int> input;

    while (toupper(choice) != 'Q') {
        cout << "\nEnter T to run correctness tests\n"
             << "Enter U to run accept user input\n"
             << "Enter E to run time tests\n"
             << "Enter Q to quit" << endl;

        cout << "Choice: ";
        cin >> choice;

        if (toupper(choice) == 'T') {
           correctness();
        } else if (toupper(choice) == 'E') {
            //TODO run time test
        } else if (toupper(choice) == 'U') {
            cout << "Input ( # # # ... -999): ";
            //TODO get user input, sort it, and display the results
        }
    }

    return 1;

}
