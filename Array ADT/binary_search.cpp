#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int element)
{
    int low = 0;
    int high = n - 1;
    int mid;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (element == arr[mid])
        {
            return mid;
        }

        else if (element < arr[mid])
        {
            high = mid - 1;
        }

        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

int main()
{
    int arr[100], n, element;

    cout << "Enter the number of elements : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int size = sizeof(arr) / sizeof(int);

    cout << "Enter the number to be searched : ";
    cin >> element;

    int searchIndex = binarySearch(arr, n, element);

    cout << "The element " << element << " is found at index : " << searchIndex;

    return 0;
}