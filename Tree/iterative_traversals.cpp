#include <iostream>
using namespace std;

struct Node
{
    Node *lchild;
    int data;
    Node *rchild;
};

struct Stack
{
    int size;
    int top;
    Node **S;
};

struct Queue
{
    int size;
    int front;
    int rear;
    Node **Q;
};

void QueueCreate(Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->Q = new Node *[q->size];
}

void enqueue(Queue *q, Node *x)
{
    if ((q->rear + 1) % q->size == q->front)
        cout << "Queue Overflow !!!";

    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

Node *dequeue(Queue *q)
{
    Node *x = NULL;

    if (q->front == q->rear)
        cout << "Queue Underflow !!!";

    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

int QisEmpty(Queue q)
{
    return q.front == q.rear;
}

void StackCreate(Stack *st, int size)
{

    st->size = size;

    st->top = -1;

    st->S = new Node *[st->size];
}

void push(Stack *st, Node *x)
{
    if (st->top == st->size - 1)
    {
        cout << "Stack Overflow !!!"
             << "\n";
    }

    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

Node *pop(Stack *st)
{
    Node *x = NULL;

    if (st->top == -1)
    {
        cout << "Stack Underflow !!!"
             << "\n";
    }

    else
    {
        x = st->S[st->top];
        st->top--;
    }

    return x;
}

bool SisEmpty(Stack st)
{
    if (st.top == -1)
    {
        return true;
    }
    return false;
}

bool isFull(Stack st)
{
    if (st.top == st.size - 1)
    {
        return true;
    }
    return false;
}

Node *root = NULL;

void Treecreate()
{
    Node *p, *t;
    int x;
    Queue q;
    QueueCreate(&q, 100);

    cout << "Enter the root value : ";
    cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while (!QisEmpty(q))
    {
        p = dequeue(&q);
        cout << "Enter the left child of " << p->data << " : ";
        cin >> x;

        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }

        cout << "Enter the right child " << p->data << " : ";
        cin >> x;

        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void preorder(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(Node *p)
{
    if (p)
    {
        inorder(p->lchild);
        cout << p->data << " ";
        inorder(p->rchild);
    }
}
void postorder(Node *p)
{
    if (p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout << p->data << " ";
    }
}

void Ipreorder(Node *p)
{
    Stack stk;
    StackCreate(&stk, 100);

    while (p || !SisEmpty(stk))
    {
        if (p)
        {
            cout << p->data << " ";
            push(&stk, p);
            p = p->lchild;
        }
        else
        {
            p = pop(&stk);
            p = p->rchild;
        }
    }
}

void Iinorder(Node *p)
{
    Stack stk;
    StackCreate(&stk, 100);

    while (p || !SisEmpty(stk))
    {
        if (p)
        {
            push(&stk, p);
            p = p->lchild;
        }
        else
        {
            p = pop(&stk);
            cout << p->data << " ";
            p = p->rchild;
        }
    }
}

int main()
{
    Treecreate();

    cout << "\nI Pre Order : ";
    Ipreorder(root);

    cout << "\nI In Order : ";
    Iinorder(root);

    return 0;
}