#include <iostream>
using namespace std;

// Useful for LinkedList
// Adaptive Behavior
// Stable

// TC: Min->O(n), Max->O(n*n)

void InsertionSort(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1, x = A[i];
        while (j >= 0 && A[j] > x)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
    }
}

int main()
{
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    int n = 10;

    InsertionSort(A, n);

    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}