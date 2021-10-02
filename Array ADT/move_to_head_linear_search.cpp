#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
        {
            swap(arr[i], arr[0]);
            return i;
        }
    }
    return -1;
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n, element;

    cout << "Enter the number of elements : ";
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int size = sizeof(arr) / sizeof(int);

    cout << "Enter the number to be searched : ";
    cin >> element;

    int searchIndex = linearSearch(arr, size, element);

    cout << "The element " << element << " is found at index : " << searchIndex << endl;

    cout << "Displaying Elements : ";
    display(arr, size);

    return 0;
}