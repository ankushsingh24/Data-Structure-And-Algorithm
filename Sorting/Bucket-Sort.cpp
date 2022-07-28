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

class Node
{
public:
    int value;
    Node *next;
};

void Insert(Node **ptrBins, int idx)
{
    Node *temp = new Node;
    temp->value = idx;
    temp->next = NULL;

    if (ptrBins[idx] == NULL)
        ptrBins[idx] = temp;
    else
    {
        Node *p = ptrBins[idx];
        while (p->next != NULL)
        {
            p = p->next;
        }
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

void BinSort(int A[], int n)
{
    Node **Bins;

    int max = findMax(A, n);
    Bins = new Node *[max + 1];

    for (int i = 0; i < max + 1; i++)
    {
        Bins[i] = NULL;
    }

    for (int i = 0; i < n; i++)
    {
        Insert(Bins, A[i]);
    }

    int i = 0, j = 0;
    while (i < max + 1)
    {
        while (Bins[i] != nullptr)
        {
            A[j++] = Delete(Bins, i);
        }
        i++;
    }

    delete[] Bins;
}

int main()
{
    int A[] = {3, 7, 9, 10, 6, 5, 102, 4, 11, 2};
    int n = 10;

    BinSort(A, n);

    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}