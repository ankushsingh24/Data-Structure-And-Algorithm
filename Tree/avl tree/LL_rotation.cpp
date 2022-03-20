#include <iostream>
using namespace std;

struct Node
{
    Node *lchild;
    int data;
    int height;
    Node *rchild;
} *root = NULL;

int NodeHeight(Node *p)
{
    int l, r;
    l = (p && p->lchild) ? p->lchild->height : 0;
    r = (p && p->rchild) ? p->rchild->height : 0;

    return l > r ? l + 1 : r + 1;
}

int BalanceFactor(Node *p)
{
    int l, r;
    l = (p && p->lchild) ? p->lchild->height : 0;
    r = (p && p->rchild) ? p->rchild->height : 0;

    return l - r;
}

Node *LL_Rotation(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;
    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if (root == p)
        root = pl;

    cout << "New Root Node : " << pl->data;

    return pl; // new root
}

Node *LR_Rotation(Node *p)
{
    return NULL;
}

Node *RR_Rotation(Node *p)
{
    return NULL;
}

Node *RL_Rotation(Node *p)
{
    return NULL;
}

Node *RecursiveInsert(Node *p, int key)
{
    Node *t = NULL;

    if (p == NULL)
    {
        t = new Node;
        t->data = key;
        t->height = 1;
        t->lchild = t->rchild = NULL;
        return t;
    }

    if (key < p->data)
        p->lchild = RecursiveInsert(p->lchild, key);
    else if (key > p->data)
        p->rchild = RecursiveInsert(p->rchild, key);

    p->height = NodeHeight(p);

    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
        return LL_Rotation(p);

    else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
        return LR_Rotation(p);

    else if (BalanceFactor(p) == -2 && BalanceFactor(p->lchild) == -1)
        return RR_Rotation(p);

    else if (BalanceFactor(p) == -2 && BalanceFactor(p->lchild) == 1)
        return RL_Rotation(p);

    return p;
}

int main()
{
    root = RecursiveInsert(root, 10);
    RecursiveInsert(root, 5);
    RecursiveInsert(root, 2);

    return 0;
}