#include <iostream>
using namespace std;

int main()
{
    char A[] = "finding";
    long int H = 0;
    int x;

    for (int i = 0; A[i] != '\0'; i++)
    {
        x = 1;
        x = x << (A[i] - 97);

        if ((x & H) > 0)
        {
            cout << "Duplicate element is : " << A[i] << endl;
        }

        else
        {
            H = H | x;
        }
    }

    return 0;
}