include "quickSort.h"

vector<int>  quickSort(vector<int> A, int p, int r)
{
    int q = -1;
    if(p < r)
    {
        q = partition(A, p, r);
        A = quickSort(A, p, q-1);
        A = quickSort(A, q+1, r);
    }

    return A;

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
