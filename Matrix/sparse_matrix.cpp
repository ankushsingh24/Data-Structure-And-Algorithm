#include <iostream>
using namespace std;

struct Element
{
    int i;
    int j;
    int x;
};

struct Sparse
{
    int m;
    int n;
    int num;
    struct Element *elements;
};

void create(struct Sparse *s)
{
    cout << "Enter the dimensions, m & n : ";
    cin >> s->m >> s->n;
    cout << "Number of non-zero elements : ";
    cin >> s->num;

    s->elements = new Element[s->num];

    cout << "Enter the non-zero elements : " << endl;
    for (int i = 0; i < s->num; i++)
    {
        cin >> s->elements[i].i >> s->elements[i].j >> s->elements[i].x;
    }
    cout << endl;
}

void display(struct Sparse s)
{
    int k = 0;

    for (int i = 0; i < s.m; i++)
    {
        for (int j = 0; j < s.n; j++)
        {
            if (i == s.elements[k].i && j == s.elements[k].j)
            {
                cout << s.elements[k++].x << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

int main()
{
    struct Sparse s;
    create(&s);
    display(s);
    return 0;
}