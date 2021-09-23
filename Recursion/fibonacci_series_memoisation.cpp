#include <iostream>
using namespace std;

// Fibonacci Series
// 0 1 1 2 3 5 8 13 21
// 0 1 2 3 4 5 6 7  8

int f[20];

int fibonacci(int n)
{
    if (n <= 1)
    {
        f[n] = n;
        return n;
    }
    else
    {
        if (f[n - 1] == -1)
        {
            f[n - 1] = fibonacci(n - 1);
        }
        if (f[n - 2] == -1)
        {
            f[n - 2] = fibonacci(n - 2);
        }

        f[n] = f[n - 1] + f[n - 2];

        return f[n - 1] + f[n - 2];
    }
}

int main()
{
    for (int i = 0; i < 20; i++)
    {
        f[i] = -1;
    }

    cout << fibonacci(8);
    return 0;
}