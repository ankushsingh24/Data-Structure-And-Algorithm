#include <iostream>
#include <string.h>
using namespace std;

void Permutation(char S[], int l, int h)
{
    int i;
    if (l == h)
    {
        cout << S << endl;
    }

    else
    {
        for (i = l; i <= h; i++)
        {
            swap(S[i], S[l]);
            Permutation(S, l + 1, h);
            swap(S[l], S[i]);
        }
    }
}

int main()
{
    char S[] = "ABC";
    int n = strlen(S) - 1;
    Permutation(S, 0, n);
    return 0;
}