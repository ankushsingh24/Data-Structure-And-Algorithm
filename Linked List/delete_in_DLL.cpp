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

int Delete(Node *p, int index)
{
    int x;

    if (index < 1 || index > length(first))
        return -1;

    if (index == 1)
    {
        first = first->next;
        if (first)
            first->prev = NULL;
        x = p->data;
        delete p;
    }

    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }

        p->prev->next = p->next;

        if (p->next)
        {
            p->next->prev = p->prev;
        }

        x = p->data;
        delete p;
    }
    return x;
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);

    Delete(first, 2);

    cout << "Length is : " << length(first) << endl;
    display(first);

    return 0;
}