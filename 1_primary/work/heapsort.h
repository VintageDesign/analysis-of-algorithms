#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


class HeapSort {
   public:
   HeapSort();

   int heapSize;

   void maxHeapify(vector<int> &A, int i);

   void buildMaxHeap(vector<int> &A);

   vector<int> heapSort(vector<int> A);

   int parent(int i);

   int left(int i);

   int right(int i);


};
