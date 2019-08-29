#include "heapsort.h"

HeapSort::HeapSort()
{
   // Intentionally left empty

}

HeapSort::heapSort(vector<int> A)
{
   this.buildMaxHeap(A);

   for(int i = A.length(); i > 2; i--)
   {
      swap(A.at(1), A.at(i));
      this.heapSize = this.heapSize - 1;
      this.maxHeapify(A, 1);
   }

}

HeapSort::buildMaxHeap(vector<int>  A)
{
   this.heapSize = A.length();
   for (int i = floor(A.length()/2); i >= 1; i--)
   {
      this.maxHeapify(A, i);
   }

}


HeapSort::maxHeapify(vector<int> A, int
