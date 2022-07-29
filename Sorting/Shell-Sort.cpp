#include <iostream>
using namespace std;

// use to sort very large size list

// TC: O(nlogn)

void ShellSort(int A[], int n)
{
    int temp, j;

    for (int gap = n / 2; gap >= 1; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            temp = A[i];
            j = i - gap;

            while (j >= 0 && A[j] > temp)
            {
                A[j + gap] = A[j];
                j = j - gap;
            }

            A[j + gap] = temp;
        }
    }
}

int main()
{
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2};
    int n = 10;

    ShellSort(A, n);

    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}