#include "quickSort.h"

// GRADING: QUICK
void  quickSort(vector<int> &A, int p, int r)
{
    int q = -1;
    if(p < r)
    {
        q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }


}

int partition(vector<int>& A, int p, int r) {
    int x = A[r];
    int i = p - 1;
    for (int j = p; j < r; j++) {
        if (A[j] <= x) {
            i = i + 1;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[r]);
    return i + 1;
}
