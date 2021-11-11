#include <iostream>
using namespace std;

struct Term
{
    int coeff;
    int exp;
};

struct Poly
{
    int n;
    struct Term *terms;
};

void create(struct Poly *p)
{
    cout << "Number of terms : ";
    cin >> p->n;

    p->terms = new Term[p->n];

    cout << "Enter the terms : \n";
    for (int i = 0; i < p->n; i++)
    {
        cin >> p->terms[i].coeff >> p->terms[i].exp;
    }
}

void display(struct Poly p)
{
    for (int i = 0; i < p.n; i++)
    {
        cout << p.terms[i].coeff << "x^" << p.terms[i].exp << "+";
    }

    cout << endl;
}

int main()
{
    struct Poly p1;

    create(&p1);
    display(p1);
    return 0;
}