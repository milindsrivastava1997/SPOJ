#include <iostream>
using namespace std;
#include <conio.h>

bool prime(int);

int main()
{
    int k;
    cin >> k;
    while (k > 0)
    {
        --k;
        int a, b;
        cin >> a >> b;
        for (int j = a; j <= b; j++)
        {
            if (prime(j))
            {
                cout << j << endl;
            }
        }
        cout << endl;
    }
    _getch();
}

bool prime(int x)
{
    if (x == 1)
        return false;
    for (int i = 2; i <= x / i; i++)
    {
        if (x%i == 0)
        {
            return false;
        }
    }
    return true;
}