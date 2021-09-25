#include <iostream>
using namespace std;

// A, B, C are three Towers of Hanoi labelled as A=1, B=2, C=3
// n is the number of discs

void TOH(int n, int a, int b, int c)
{
    if (n > 0)
    {
        TOH(n - 1, a, c, b);
        cout << "Move " << a << " -> " << c << endl;
        TOH(n - 1, b, a, c);
    }
}

int main()
{
    cout << "Process To Follow : " << endl;
    TOH(3, 1, 2, 3);
    cout << "Problem Solved Successfully";
    return 0;
}