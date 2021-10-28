#include <iostream>
using namespace std;

void Permutation(char S[], int k)
{
    static int A[10] = {0};
    static char Result[10];
    int i = 0;

    if (S[k] == '\0')
    {
        Result[k] = '\0';
        cout << Result << endl;
    }

    else
    {
        for (i = 0; S[i] != '\0'; i++)
        {
            if (A[i] == 0)
            {
                Result[k] = S[i];
                A[i] = 1;
                Permutation(S, k + 1);
                A[i] = 0;
            }
        }
    }
}

int main()
{
    char S[] = "ABC";
    Permutation(S, 0);
    return 0;
}