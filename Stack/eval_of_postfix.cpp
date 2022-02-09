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

int precedence(char x)
{
    if (x == '+' || x == '-')
        return 1;

    else if (x == '*' || x == '/')
        return 2;
    else
        return 0;
}

int isOperand(char x) // variable or number
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}

int evaluate(char *postifix)
{
    int a, b, result;

    for (int i = 0; postifix[i] != '\0'; i++)
    {
        if (isOperand(postifix[i]))
            push(postifix[i] - '0');

        else
        {
            b = pop();
            a = pop();
            switch (postifix[i])
            {
            case '+':
                result = a + b;
                break;
            case '-':
                result = a - b;
                break;
            case '*':
                result = a * b;
                break;
            case '/':
                result = a / b;
                break;
            default:
                break;
            }
            push(result);
        }
    }
    return top->data;
}

int main()
{
    char *postifix = (char *)"234*+82/-";
    cout << evaluate(postifix);
    return 0;
}