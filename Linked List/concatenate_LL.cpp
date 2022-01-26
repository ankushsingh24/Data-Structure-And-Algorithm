#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;

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

void create2(int A[], int n)
{
    struct Node *t, *last;
    second = new Node;
    second->data = A[0];
    second->next = NULL;
    last = second;

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

void Concat(Node *p, Node *q)
{
    third = p;

    while (p->next != NULL)
    {
        p = p->next;
    }

    p->next = q;
}

int main()
{
    int A[] = {0, 2, 4, 6, 8};
    int B[] = {1, 3, 5, 7, 9};

    create(A, 5);
    create2(B, 5);

    Concat(first, second);
    cout << "Concatenated : ";
    display(third);

    return 0;
}