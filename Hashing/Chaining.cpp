#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
} *first = NULL;

void sortedInsert(Node **H, int x)
{
    Node *t, *q = NULL, *p = *H;
    t = new Node;
    t->data = x;
    t->next = NULL;

    if (*H == NULL)
    {
        *H = t;
    }

    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }

        if (p == *H)
        {
            t->next = *H;
            *H = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

Node *Search(Node *p, int key)
{
    while (p != NULL)
    {
        if (key == p->data)
        {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

int Hash(int key)
{
    return (key % 10);
}

void Insert(Node *H[], int key)
{
    int index = Hash(key);
    sortedInsert(&H[index], key);
}

int main()
{
    Node *HT[10];
    Node *temp;

    for (int i = 0; i < 10; i++)
    {
        HT[i] = NULL;
    }

    Insert(HT, 12);
    Insert(HT, 22);
    Insert(HT, 42);

    temp = Search(HT[Hash(22)], 22);

    cout << temp->data;

    return 0;
}