#include <iostream>
using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

class Queue
{
private:
    int front;
    int rear;
    int size;
    Node **Q;

public:
    Queue()
    {
        front = rear = -1;
        size = 10;
        Q = new Node *[size];
    }

    Queue(int size)
    {
        front = rear = -1;
        this->size = size;
        Q = new Node *[this->size];
    }

    void enqueue(Node *x);
    Node *dequeue();
    int isEmpty();
    void display();
};

void Queue::enqueue(Node *x)
{
    if (rear == size - 1)
        cout << "Queue is Full !!!\n";

    rear++;
    Q[rear] = x;
}

Node *Queue::dequeue()
{
    Node *x = NULL;
    if (rear == front)
        cout << "Queue is Empty !!!\n";

    x = Q[front + 1];
    front++;
    return x;
}

int Queue::isEmpty()
{
    return front == rear;
}

void Queue::display()
{
    for (int i = 0; i <= rear; i++)
    {
        cout << Q[i] << " ";
    }
    cout << "\n";
}

class Tree
{
public:
    Node *root;
    Tree()
    {
        root = NULL;
    }
    void createTree();
    void preorder(Node *p);
    void postorder(Node *p);
    void inorder(Node *p);
    void levelorder(Node *p);
    int height(Node *root);
};

void Tree::createTree()
{
    Node *p, *t;
    int x;
    Queue q(100);

    cout << "Enter the root value : ";
    cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);

    while (!q.isEmpty())
    {
        p = q.dequeue();
        cout << "Enter the left child of " << p->data << " : ";
        cin >> x;

        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }

        cout << "Enter the right child " << p->data << " : ";
        cin >> x;

        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree::preorder(Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void Tree::inorder(Node *p)
{
    if (p)
    {
        inorder(p->lchild);
        cout << p->data << " ";
        inorder(p->rchild);
    }
}
void Tree::postorder(Node *p)
{
    if (p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout << p->data << " ";
    }
}

void Tree::levelorder(Node *root)
{
    cout << "Leavelorder : ";
    Queue q(100);

    cout << root->data << " ";
    q.enqueue(root);

    while (!q.isEmpty())
    {
        root = q.dequeue();
        if (root->lchild)
        {
            cout << root->lchild->data << " ";
            q.enqueue(root->lchild);
        }

        if (root->rchild)
        {
            cout << root->rchild->data << " ";
            q.enqueue(root->rchild);
        }
    }
    cout << "\n";
}

int Tree::height(Node *root)
{
    int x = 0, y = 0;

    if (root == 0)
        return 0;

    x = height(root->lchild);
    y = height(root->rchild);

    return x > y ? (x + 1) : (y + 1);
}

int main()
{
    Tree t;
    t.createTree();

    cout << "Preorder : ";
    t.preorder(t.root);
    cout << endl;

    cout << "Inorder : ";
    t.inorder(t.root);
    cout << endl;

    cout << "Postorder : ";
    t.postorder(t.root);
    cout << endl;

    return 0;
}