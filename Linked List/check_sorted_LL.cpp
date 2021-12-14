#include <iostream>
#include <limits.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void create(int A[], int n)
{
    struct Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->data << "\t";
        p = p->next;
    }
}

int isSorted(struct Node *p)
{
    int x = INT_MIN;

    while (p != NULL)
    {
        if (p->data < x)
            return false;

        x = p->data;
        p = p->next;
    }

    return true;
}

int main()
{
    int A[] = {10, 20, 3, 40, 50};
    create(A, 5);
    display(first);

    cout << endl;

    cout << isSorted(first);

    return 0;
}