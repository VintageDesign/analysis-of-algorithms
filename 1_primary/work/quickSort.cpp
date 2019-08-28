#include "quickSort.h"

vector<int> quickSort(vector<int> A, int p, int r)
{
    int q = -1;
    if(p < r)
    {
        q = partition(A, p, r);
        quickSort(A, p, q-1);
        quickSort(A, q+1, r);
    }

    return A;
}


int partition(vector<int> &A, int p, int r)
{
    int x = A.at(r);
    int temp = 0;
    int i = p - 1;

    for(int j = p; j < r - 1; j++)
    {
        if( A.at(j) <= x)
        {
           i = i + 1;
           temp = A.at(i);
           A.at(i) = A.at(j);
           A.at(j) = temp;
        }
    }

    temp = A.at(i+1);
    A.at(i+1) = A.at(r);
    A.at(r) = temp;

    return i + 1;

}
