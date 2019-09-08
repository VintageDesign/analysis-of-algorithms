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




void timeTest(void);

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

vector<int> generateVector(int length)
{
    vector<int> list;
    for(int i = 0; i < length; i++)
    {
        list.push_back(rand() % 1000);
    }

    return list;
}


void manualSort(vector<int> input)
{
    HeapSort heap = HeapSort();
    vector<int> quickSortResult;
    vector<int> heapSortResult;

    cout << "Manual Sort" << endl;
    cout << "Original: ";
    printVector(input);
    cout << "Quick Result: ";
    quickSortResult = input;
    quickSort(quickSortResult, 0, input.size());
    printVector(quickSortResult);
    cout << "Heap Result: ";
    //TODO test, and display result
    heapSortResult = heap.heapSort(input);
    printVector(heapSortResult);

    cout << endl;

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
    vector<int> test4 = generateVector(9);
    //  test 4 with 9 random numbers


    HeapSort heap = HeapSort();

    cout << "Test 1: Basic sort with 2 elements" << endl;
    cout << "Original: 2, 1" << endl;
    cout << "Quick Result: ";
    quickSortResult = test1;
    quickSort(quickSortResult, 0, 1);
    printVector(quickSortResult);
    cout << "Heap Result: ";
    //TODO test, and display result
    heapSortResult = heap.heapSort(test1);
    printVector(heapSortResult);

    cout << endl;

    cout << "Test 2: Basic sort with 3 elements" << endl;
    cout << "Original: 1, 3, 2" << endl;
    cout << "Quick Result: ";
    quickSortResult = test2;
    quickSort(quickSortResult, 0, 2);
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
    quickSortResult = test3;
    quickSort(quickSortResult, 0, 7);
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
    quickSortResult = test4;
    quickSort(quickSortResult, 0, 8);
    printVector(quickSortResult);
    checkSort(quickSortResult, test4);
    cout << "Heap Result: ";
    heapSortResult = heap.heapSort(test4);
    printVector(heapSortResult);
    checkSort(heapSortResult, test4);

}



int main() {
    int value;
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
            timeTest();
        } else if (toupper(choice) == 'U') {
            cout << "Input ( # # # ... -999): ";
            input.clear();
            cin >> value;
            while( value != -999)
            {
               input.push_back(value);
               cin >> value;

            }

            manualSort(input);

        }
    }

    return 1;

}



void timeTest(void)
{
    vector<int> testSizes = { 50, 100, 200, 500, 1000, 2000, 10000, 50000, 100000, 200000, 500000
                            , 1000000 };
    vector<int> unsortedList;
    vector<int> sortedList;
    vector<int> quickSortResult;
    vector<int> heapSortResult;
    clock_t     startTime;
    clock_t     endTime;
    double      time;

    for(int size : testSizes)
    {
        unsortedList = generateVector(size);
        sortedList = unsortedList;

        HeapSort heap = HeapSort();

        cout << "Test Size: " << size << endl;
        cout << "Quick Result: ";
        startTime = clock();
        quickSort(sortedList, 0, size-1);
        endTime = clock();
        time = (double) (endTime - startTime) / CLOCKS_PER_SEC;
        cout << time << endl;
        checkSort(sortedList, unsortedList);
        cout << "Heap Result: ";
        startTime = clock();
        heapSortResult = heap.heapSort(unsortedList);
        endTime = clock();
        time = (double) (endTime - startTime) / CLOCKS_PER_SEC;
        cout << time << endl;
        checkSort(heapSortResult, unsortedList);
    }



}
