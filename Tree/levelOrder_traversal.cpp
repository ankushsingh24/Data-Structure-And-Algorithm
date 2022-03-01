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

void levelOrder(Node *root)
{
    Queue q;
    QueueCreate(&q, 100);

    cout << root->data << " ";
    enqueue(&q, root);

    while (!QisEmpty(q))
    {
        root = dequeue(&q);

        if (root->lchild)
        {
            cout << root->lchild->data << " ";
            enqueue(&q, root->lchild);
        }

        if (root->rchild)
        {
            cout << root->rchild->data << " ";
            enqueue(&q, root->rchild);
        }
    }
}

int main()
{
    Treecreate();

    cout << "\nLevel Order : ";
    levelOrder(root);

    return 0;
}