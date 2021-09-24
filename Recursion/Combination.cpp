#include <iostream>
using namespace std;

// nCr = n! / (r! * (n - r)!)

// 1
int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

int combination(int n, int r)
{
    int a, b, c;

    a = factorial(n);
    b = factorial(r);
    c = factorial(n - r);

    return a / (b * c);
}

// 2
int PascalCombination(int n, int r)
{
    if (n == r || r == 0)
    {
        return 1;
    }

    return PascalCombination(n - 1, r - 1) + PascalCombination(n - 1, r);
}

int main()
{
    cout << combination(5, 2) << endl;                              // 10
    cout << PascalCombination(5, 2) << endl;                        // 10
    cout << (combination(5, 2) == PascalCombination(5, 2)) << endl; // 1
    return 0;
}