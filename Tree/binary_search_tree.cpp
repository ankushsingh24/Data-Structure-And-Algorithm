#include <iostream>
using namespace std;

struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = NULL;

void insert(int key)
{
    Node *t = root;
    Node *r = NULL, *p;

    if (root == NULL)
    {
        p = new Node;
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }

    while (t != NULL)
    {
        r = t;

        if (key < t->data)
            t = t->lchild;
        else if (key > t->data)
            t = t->rchild;
        else
            return;
    }

    p = new Node;
    p->data = key;
    p->lchild = p->rchild = NULL;

    if (key < r->data)
        r->lchild = p;
    else if (key > r->data)
        r->rchild = p;
}

Node *RecursiveInsert(Node *p, int key)
{
    Node *t = NULL;

    if (p == NULL)
    {
        t = new Node;
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }

    if (key < p->data)
        p->lchild = RecursiveInsert(p->lchild, key);
    else if (key > p->data)
        p->rchild = RecursiveInsert(p->rchild, key);

    return p;
}

void inOrder(Node *p)
{
    if (p)
    {
        inOrder(p->lchild);
        cout << p->data << " ";
        inOrder(p->rchild);
    }
}

Node *search(int key)
{
    Node *t = root;

    while (t != NULL)
    {
        if (key < t->data)
            t = t->lchild;
        else if (key > t->data)
            t = t->rchild;
        else
            return t;
    }
    return NULL;
}

int main()
{
    // insert(10);
    // insert(5);
    // insert(20);
    // insert(8);
    // insert(30);

    root = RecursiveInsert(root, 10);
    RecursiveInsert(root, 5);
    RecursiveInsert(root, 20);
    RecursiveInsert(root, 8);
    RecursiveInsert(root, 30);

    inOrder(root);
    cout << endl;

    Node *temp;
    temp = search(20);
    if (temp != NULL)
        cout << "Element " << temp->data << " Found\n";
    else
        cout << "Element Not Found\n";
    return 0;
}