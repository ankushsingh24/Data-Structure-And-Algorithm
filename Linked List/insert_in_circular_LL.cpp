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
        cout << p->data << "\t";
        p = p->next;
    } while (p != head);
}

void recursive_display(Node *p)
{
    static int flag = 0;

    if (p != head || flag == 0)
    {
        flag = 1;
        cout << p->data << "\t";
        recursive_display(p->next);
    }
    flag = 0;
}

int length(Node *p)
{
    int len = 0;

    do
    {
        len++;
        p = p->next;
    } while (p != head);

    return len;
}

void insert(Node *p, int index, int x)
{
    Node *t;

    if (index < 0 || index > length(head))
        return;

    if (index == 0) // inserting before head if index = 0
    {
        t = new Node;
        t->data = x;

        if (head == NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {
            while (p->next != head)
            {
                p = p->next;
            }
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }

        t = new Node;
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}

int main()
{
    int A[] = {0, 2, 4, 6, 8};
    create(A, 5);

    insert(head, 2, 10);

    display(head);
    // recursive_display(head);

    return 0;
}