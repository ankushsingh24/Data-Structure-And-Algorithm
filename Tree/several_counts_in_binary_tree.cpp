#include <iostream>
using namespace std;

struct Node
{
    Node *lchild;
    int data;
    Node *rchild;
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

int count_nodes(Node *root)
{
    int x, y;
    if (root == NULL)
        return 0;

    x = count_nodes(root->lchild);
    y = count_nodes(root->rchild);
    return x + y + 1;
}

int height(Node *root)
{
    int x, y;
    if (root == NULL)
        return 0;

    x = height(root->lchild);
    y = height(root->rchild);

    if (x > y)
        return x + 1;
    else
        return y + 1;
}

int main()
{
    Treecreate();

    cout << "\nNo of nodes : " << count_nodes(root);
    cout << "\nHeight : " << height(root);

    return 0;
}