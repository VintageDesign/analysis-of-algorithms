#include "heapsort.h"

HeapSort::HeapSort()
{
   // Intentionally left empty

}

vector<int> HeapSort::heapSort(vector<int> A)
{
   buildMaxHeap(A);

   for(int i = A.size() - 1; i >= 1; i--)
   {
      swap(A.at(0), A.at(i));
      heapSize = heapSize - 1;
      maxHeapify(A, 0);
   }

   return  A;
}

void HeapSort::buildMaxHeap(vector<int> &A)
{
   heapSize = A.size();
   for (int i = floor(A.size()/2); i >= 0; i--)
   {
      maxHeapify(A, i);
   }

}


void HeapSort::maxHeapify(vector<int> &A, int i)
{
   int l = left(i);
   int r = right(i);
   int largest = 0;

   if (l < heapSize && A[l] > A[i])
   {
       largest = l;
   }
   else
   {
      largest = i;
   }

   if (r < heapSize && A[r] > A[i])
   {
       largest = r;
   }
   else
   {
      largest = i;
   }
   if (largest != i )
    {
       swap(A.at(i), A.at(largest));
        maxHeapify(A, largest);
    }
}


int HeapSort::parent(int i)
{
   return floor(i/2);

}
int HeapSort::left(int i)
{
    return  2 * i;
}

int HeapSort::right(int i)
{
    return  2 * i + 1;
}
