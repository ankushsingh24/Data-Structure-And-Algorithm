#include <iostream>
using namespace std;

// Other names:
// Selection Exchange Sort
// Partition Exchange Sort

// TC: Min->O(nlogn), Max->O(n^2)

// Best case: If partitioning is happening in the middle
// Worst case: Already sorted
// Avg case: O(nlogn)

int Partition(int A[], int low, int high)
{
    int pivot = A[low];
    int i = low, j = high;

    do
    {
        do
        {
            i++;
        } while (A[i] <= pivot);
        do
        {
            j--;
        } while (A[j] > pivot);

        if (i < j)
        {
            swap(A[i], A[j]);
        }

    } while (i < j);

    swap(A[low], A[j]);

    return j;
}

void QuickSort(int A[], int low, int high)
{
    if (low < high)
    {
        int j = Partition(A, low, high);
        QuickSort(A, low, j);
        QuickSort(A, j + 1, high);
    }
}

int main()
{
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2, INT32_MAX};
    int n = 11;

    QuickSort(A, 0, n - 1);

    for (int i = 0; i < 10; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}