#include <iostream>
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

void sortedInsert(struct Node *p, int x)
{
    struct Node *t, *q = NULL;
    t = new Node;
    t->data = x;
    t->next = NULL;

    if (first == NULL)
    {
        first = t;
    }

    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }

        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    display(first);

    cout << endl;

    sortedInsert(first, 12);
    display(first);
    return 0;
}