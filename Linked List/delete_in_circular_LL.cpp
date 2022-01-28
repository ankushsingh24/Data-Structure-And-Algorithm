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
        cout << p->data;
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

int Delete(Node *p, int index)
{
    Node *q;
    int x;

    if (index < 0 || index > length(head))
        return -1;

    if (index == 1)
    {
        while (p->next != head)
        {
            p = p->next;
        }

        x = head->data;

        if (head == p)
        {
            delete head;
            head = NULL;
        }
        else
        {
            p->next = head->next;
            delete head;
            head = p->next;
        }
    }

    else
    {
        for (int i = 0; i < index - 2; i++)
        {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        x = q->data;
        delete q;
    }
}

int main()
{
    int A[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    create(A, 10);

    Delete(head, 3);

    display(head);
    // recursive_display(head);

    return 0;
}