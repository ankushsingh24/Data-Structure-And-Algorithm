#include <iostream>
using namespace std;

struct Node
{
    Node *prev;
    int data;
    Node *next;
} *first = NULL;

void create(int A[], int n)
{
    Node *t, *last;

    first = new Node;
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->prev = last;
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(Node *p)
{
    while (p)
    {
        cout << p->data << "\t";
        p = p->next;
    }
}

int length(Node *p)
{
    int i = 0;
    while (p)
    {
        i++;
        p = p->next;
    }
    return i;
}

void insert(Node *p, int index, int x)
{
    Node *t;

    if (index < 0 || index > length(first))
        return;

    if (index == 0)
    {
        t = new Node;
        t->data = x;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }

        t = new Node;
        t->data = x;
        t->prev = p;
        t->next = p->next;

        if (p->next)
            p->next->prev = t;
        p->next = t;
    }
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);

    insert(first, 2, 25);

    cout << "Length is : " << length(first) << endl;
    display(first);

    return 0;
}