#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

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

void insert(struct Node *p, int index, int x)
{
    if (index < 0 && index > count(p)) // checking range
        return;

    struct Node *t;
    t = new Node;
    t->data = x;

    if (index == 0)
    {
        t->next = first;
        first = t;
    }

    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }

        t->next = p->next;
        p->next = t;
    }
}

int main()
{
    insert(first, 0, 10);
    insert(first, 1, 20);
    insert(first, 2, 30);
    insert(first, 0, 5);
    display(first);
    return 0;
}