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

void recursive_Display(struct Node *p)
{
    if (p != NULL)
    {
        cout << p->data << "\t";
        recursive_Display(p->next);
    }
}

void recursive_backward_Display(struct Node *p)
{
    if (p != NULL)
    {
        recursive_Display(p->next);
        cout << p->data << "\t";
    }
}

int main()
{
    int A[] = {3, 5, 7, 10, 15};
    create(A, 5);
    recursive_Display(first);
    cout << "\n";
    recursive_backward_Display(first);
    return 0;
}