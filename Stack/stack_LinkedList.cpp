#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
} *top = NULL;

void push(int x)
{
    Node *t = new Node;

    if (t == NULL)
    {
        cout << "Stack Overflow !!!\n";
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop()
{
    Node *t;
    int x = -1;

    if (top == NULL)
    {
        cout << "Stack Underflow !!!\n";
    }
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    return x;
}

void Display()
{
    Node *p;
    p = top;

    cout << "Stack contains : ";
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << "\n";
}

int main()
{
    push(10);
    push(20);
    push(30);

    Display();

    cout << pop() << "\n";

    Display();
    return 0;
}