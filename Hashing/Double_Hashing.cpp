#include <iostream>
using namespace std;

#define SIZE 10
#define PRIME 7

int Hash(int key)
{
    return key % SIZE;
}

int PrimeHash(int key)
{
    return PRIME - (key % PRIME);
}

int DoubleHash(int H[], int key)
{
    int idx = Hash(key);
    int i = 0;
    while (H[(Hash(idx) + i * PrimeHash(idx)) % SIZE] != 0)
    {
        i++;
    }
    return (idx + i * PrimeHash(idx)) % SIZE;
}

void Insert(int H[], int key)
{
    int idx = Hash(key);

    if (H[idx] != 0)
    {
        idx = DoubleHash(H, key);
    }
    H[idx] = key;
}

int Search(int H[], int key)
{
    int idx = Hash(key);
    int i = 0;
    while (H[(Hash(idx) + i * PrimeHash(idx)) % SIZE] != key)
    {
        i++;
        if (H[(Hash(idx) + i * PrimeHash(idx)) % SIZE] == 0)
        {
            return -1;
        }
    }
    return (Hash(idx) + i * PrimeHash(idx)) % SIZE;
}

int main()
{
    int A[] = {5, 25, 15, 35, 95};
    int n = sizeof(A) / sizeof(A[0]);

    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    cout << endl;
    // Hash Table
    int HT[10] = {0};
    for (int i = 0; i < n; i++)
    {
        Insert(HT, A[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        cout << HT[i] << " ";
    }

    int index = Search(HT, 25);
    cout << "\nkey found at: " << index << endl;

    index = Search(HT, 35);
    cout << "key found at: " << index << endl;
    return 0;
}