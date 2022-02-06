#include <iostream>
using namespace std;

struct Node
{
    char data;
    Node *next;
} *top = NULL;

void push(char x)
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

char pop()
{
    Node *t;
    char x = -1;

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

int isBalanced(char *exp)
{
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            push(exp[i]);
        }

        else if (exp[i] == ')')
        {
            if (top == NULL)
                return false;
            pop();
        }
    }
    if (top == NULL)
        return true;
    else
        return false;
}

int main()
{
    // char *exp = "((a+b)*(c-d))"; <--- giving warning in c++
    char *exp = (char *)"((a+b)*(c-d))";
    cout << isBalanced(exp);
    return 0;
}