#include <iostream>
#include <cmath>
using namespace std;

// Same as bin/ bucket sort but it consists of smaller size
// d-> no of digits in the largest no

// TC: O(nd) or O(n)
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

class Node
{
public:
    int value;
    Node *next;
};

int countDigits(int x)
{
    int count = 0;
    while (x != 0)
    {
        x = x / 10;
        count++;
    }

    return count;
}

void initializeBins(Node **p, int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i] = NULL;
    }
}

int getBinIndex(int x, int idx)
{
    return (int)(x / pow(10, idx)) % 10;
}

void Insert(Node **ptrBins, int value, int idx)
{
    Node *temp = new Node;
    temp->value = value;
    temp->next = NULL;

    if (ptrBins[idx] == NULL)
    {
        ptrBins[idx] = temp;
    }

    else
    {
        Node *p = ptrBins[idx];
        while (p->next != NULL)
        {
            p = p->next;
        }

        p->next = temp;
    }
}

int Delete(Node **ptrBins, int idx)
{
    Node *p = ptrBins[idx];
    ptrBins[idx] = ptrBins[idx]->next;

    int x = p->value;
    delete p;

    return x;
}

void RadixSort(int A[], int n)
{
    int max = findMax(A, n);
    int nPass = countDigits(max);

    Node **bins = new Node *[10];

    initializeBins(bins, 10);

    for (int pass = 0; pass < nPass; pass++)
    {
        for (int i = 0; i < n; i++)
        {
            int binIdx = getBinIndex(A[i], pass);
            Insert(bins, A[i], binIdx);
        }

        int i = 0, j = 0;
        while (i < 10)
        {
            while (bins[i] != NULL)
            {
                A[j++] = Delete(bins, i);
            }
            i++;
        }
        initializeBins(bins, 10);
    }
    delete[] bins;
}

int main()
{
    int A[] = {3, 7, 9, 10, 6, 5, 102, 4, 11, 2};
    int n = 10;

    RadixSort(A, n);

    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}