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

    return 0;
}