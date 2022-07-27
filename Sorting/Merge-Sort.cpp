#include <iostream>
using namespace std;

void Merge(int A[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int B[20];

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }

    for (; i <= mid; i++)
        B[k++] = A[i];

    for (; j <= high; j++)
        B[k++] = A[j];

    for (int i = low; i <= high; i++)
        A[i] = B[i];
}

void IMergeSort(int A[], int n)
{
    int p, low, mid, high;
    for (p = 2; p < n; p = p * 2)
    {
        for (int i = 0; i + p - 1 < n; i = i + p)
        {
            low = i;
            high = low + p - 1;
            mid = (low + high) / 2;

            Merge(A, low, mid, high);
        }
    }

    if (p / 2 < n)
        Merge(A, 0, p / 2 - 1, n - 1);
}

int main()
{
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    int n = 10;

    IMergeSort(A, n);

    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}