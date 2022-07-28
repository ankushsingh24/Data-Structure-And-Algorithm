#include <iostream>
using namespace std;

// index based sorting
// fastest but consumes a lot of memory

// TC: O(n)
// SC: O(n)

int findMax(int A[], int n)
{
    int max = INT32_MIN;

    for (int i = 1; i < n; i++)
    {
        if (max < A[i])
            max = A[i];
    }

    return max;
}

void CountSort(int A[], int n)
{
    int *Count;

    int max = findMax(A, n);
    Count = new int[max + 1];

    for (int i = 0; i < max + 1; i++)
    {
        Count[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        Count[A[i]]++;
    }

    int i = 0, j = 0;
    while (j < max + 1)
    {
        if (Count[j] > 0)
        {
            A[i++] = j;
            Count[j]--;
        }
        else
            j++;
    }
}

int main()
{
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    int n = 10;

    CountSort(A, n);

    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}