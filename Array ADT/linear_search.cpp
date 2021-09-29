#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            return i;
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

    int searchIndex = linearSearch(arr, size, element);

    cout << "The element " << element << " is found at index : " << searchIndex;

    return 0;
}