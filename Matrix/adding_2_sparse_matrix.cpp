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

    cout << "Enter the non-zero elements : \n";
    for (int i = 0; i < s->m; i++)
    {
        cin >> s->elements[i].i >> s->elements[i].j >> s->elements[i].x;
    }
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

struct Sparse *add(struct Sparse *s1, struct Sparse *s2)
{
    struct Sparse *sum;
    int i, j, k;
    i = j = k = 0;

    sum = new Sparse;
    sum->elements = new Element[s1->num + s2->num];

    while (i < s1->num && j < s2->num)
    {
        if (s1->elements[i].i < s2->elements[j].i)
            sum->elements[k++] = s1->elements[i++];
        else if (s1->elements[i].i > s2->elements[j].i)
            sum->elements[k++] = s2->elements[j++];
        else
        {
            if (s1->elements[i].j < s2->elements[j].j)
                sum->elements[k++] = s1->elements[i++];
            else if (s1->elements[i].j > s2->elements[j].j)
                sum->elements[k++] = s2->elements[j++];
            else
            {
                sum->elements[k] = s1->elements[i++];
                sum->elements[k++].x += s2->elements[j++].x;
            }
        }
    }

    for (; i < s1->num; i++)
        sum->elements[k++] = s1->elements[i];
    for (; j < s2->num; j++)
        sum->elements[k++] = s2->elements[j];

    sum->m = s1->m;
    sum->n = s1->n;
    sum->num = k;
}

int main()
{
    struct Sparse s1, s2, *s3;
    create(&s1);
    create(&s2);

    s3 = add(&s1, &s2);
    cout << "First Matrix:\n";
    display(s1);
    cout << "Second Matrix:\n";
    display(s2);
    cout << "Sum Matrix:\n";
    display(*s3);
    return 0;
}