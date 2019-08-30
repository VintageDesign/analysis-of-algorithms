#include <iostream>
#include <iomanip>
#include <time.h>
#include <vector>
#include <chrono>
#include <algorithm>
#include <string>
#include <cstdlib>

#include "quickSort.h"
#include "heapsort.h"
using namespace std;

void printVector(vector<int> sortResult)
{

    for (int i = 0; i < sortResult.size(); i++)
    {
       cout << sortResult.at(i);

       if( i < sortResult.size() - 1)
       {
           cout << ", ";
       }
    }
    cout << endl;
    return;
}


void checkSort(vector<int> sortedResult, vector<int> original)
{
    sort(original.begin(), original.end());

    string passFlag =  original == sortedResult ? "Pass" : "Fail";
    cout << passFlag << endl;
}

/******************************************************
Template function for running correctness tests
GRADING: CORRECTNESS TESTS
******************************************************/
void correctness() {
    vector<int> quickSortResult;
    vector<int> heapSortResult;
    vector<int> test1 = { 2,1 };
    vector<int> test2 = { 1, 3, 2 };
    vector<int> test3 = { 2, 2, 1, 3, 5, 4, 8, 0 };
    vector<int> test4;
    //  test 4 with 9 random numbers
    for(int i = 0; i < 9; i++)
    {
        test4.push_back(rand() % 100);
    }


    HeapSort heap = HeapSort();

    cout << "Test 1: Basic sort with 2 elements" << endl;
    cout << "Original: 2, 1" << endl;
    cout << "Quick Result: ";
    quickSortResult = quickSort(test1, 0, 1);
    printVector(quickSortResult);
    checkSort(quickSortResult, test1);
    cout << "Heap Result: ";
    //TODO test, and display result
    heapSortResult = heap.heapSort(test1);
    printVector(heapSortResult);
    checkSort(heapSortResult, test1);

    cout << endl;

    cout << "Test 2: Basic sort with 3 elements" << endl;
    cout << "Original: 1, 3, 2" << endl;
    cout << "Quick Result: ";
    quickSortResult = quickSort(test2, 0, 2);
    printVector(quickSortResult);
    checkSort(quickSortResult, test2);
    cout << "Heap Result: ";
    heapSortResult = heap.heapSort(test2);
    printVector(heapSortResult);
    checkSort(heapSortResult, test2);

    cout << endl;

    cout << "Test 3: Basic sort with even # of elements" << endl;
    cout << "Original: 2, 2, 1, 3, 5, 4, 8, 0 " << endl;
    cout << "Quick Result: ";
    quickSortResult = quickSort(test3, 0, 7);
    printVector(quickSortResult);
    checkSort(quickSortResult, test3);
    cout << "Heap Result: ";
    heapSortResult = heap.heapSort(test3);
    printVector(heapSortResult);
    checkSort(heapSortResult, test3);

    cout << endl;

    cout << "Test 4: Basic sort with odd # of elements" << endl;
    cout << "Original: "  << endl; //TODO print 9 random values
    cout << "Quick Result: ";
    //TODO test, and display result...TIP you can write a generic test if you check A[i+1] > A[i]
    quickSortResult = quickSort(test4, 0, 8);
    printVector(quickSortResult);
    checkSort(quickSortResult, test4);
    cout << "Heap Result: ";
    heapSortResult = heap.heapSort(test4);
    printVector(heapSortResult);
    checkSort(heapSortResult, test4);

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
