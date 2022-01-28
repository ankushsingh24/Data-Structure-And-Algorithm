#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
} * head;

void create(int A[], int n)
{
    Node *t, *last;
    head = new Node;
    head->data = A[0];
    head->next = head;
    last = head;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void display(Node *p)
{
    do
    {
        cout << p->data;
        p = p->next;
    } while (p != head);
}

void recursive_display(Node *p)
{
    static int flag = 0;

    if (p != head || flag == 0)
    {
        flag = 1;
        cout << p->data;
        recursive_display(p->next);
    }
    flag = 0;
}

int main()
{
    int A[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    create(A, 10);

    display(head);
    // recursive_display(head);

    return 0;
}