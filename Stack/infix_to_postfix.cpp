#include <iostream>
#include <string.h>
using namespace std;

struct Node
{
    char data;
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

int precedence(char x)
{
    if (x == '+' || x == '-')
        return 1;

    else if (x == '*' || x == '/')
        return 2;
    else
        return 0;
}

int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}

char *InToPost(char *infix)
{
    int i = 0, j = 0;
    char *postfix;
    long length = strlen(infix);
    postfix = new char[length + 2];

    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];

        else
        {
            if (precedence(infix[i]) > precedence(top->data))
                push(infix[i++]);

            else
                postfix[j++] = pop();
        }
    }

    while (top != NULL)
        postfix[j++] = pop();

    postfix[j] = '\0';

    return postfix;
}

int main()
{
    char *infix = (char *)"a+b*c-d/e";
    push('#'); // added to get rid of error on line 93

    char *postfix = InToPost(infix);

    cout << postfix;

    return 0;
}