#include <iostream>
using namespace std;

// Good for less no of swaps
// Not Adaptive
// Not Stable

// TC: Min->O(n), Max->O(n*n)

void SelectionSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int j, k;
        for (j = k = i; j < n; j++)
        {
            if (A[j] < A[k])
                k = j;
        }
        swap(A[i], A[k]);
    }
}

int main()
{
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    int n = 10;

    SelectionSort(A, n);

    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}