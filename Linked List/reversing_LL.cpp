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

int count(struct Node *p)
{
    int i = 0;
    while (p)
    {
        i++;
        p = p->next;
    }
    return i;
}

void reverse1(struct Node *p)
{
    int *A, i = 0;
    struct Node *q = p;

    A = new int[count(p)];

    while (q != NULL)
    {
        A[i++] = q->data;
        q = q->next;
    }

    q = p;
    i--;

    while (q != NULL)
    {
        q->data = A[i--];
        q = q->next;
    }
}

void reverse2(struct Node *p)
{
    struct Node *r = NULL, *q = NULL;

    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void reverse3(struct Node *q, struct Node *p)
{
    if (p)
    {
        reverse3(p, p->next);
        p->next = q;
    }

    else
        first = q;
}

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    display(first);

    cout << "\nAfter Reversing\n";

    // reverse1(first);
    // reverse2(first);
    reverse3(NULL, first);
    display(first);

    return 0;
}