#include <iostream>
using namespace std;
#include <conio.h>
#include <string.h>

struct number
{
    char arr[1000000];
};

int main()
{
    
    int k;
    cin >> k;
    cin.ignore();
    while (k > 0)
    {
        --k;

        number x = { '\0' };
        
        cin.getline(x.arr,1000000);
        //cout << x.arr<<endl;

        int len = strlen(x.arr);
        //cout << len<<endl;
        /*if (len == 1)
        {
            cout << "11";
            continue;
        }*/

        bool isPalin = true;
        bool allNines = true;
        for (int i = 0; i <= len / 2; i++)
        {
            if (x.arr[i] != x.arr[len - i - 1])
            {
                isPalin = false;
                allNines = false;
            }
            else
            {
                if (x.arr[i] != '9')
                {
                    allNines = false;
                }
            }
        }
        if (allNines == true)
        {
            cout << "1";
            for (int i = 1; i <= len - 1; i++)
            {
                cout << "0";
            }
            cout << "1"<<endl;
            continue;
        }
        if (isPalin == true)
        {
            //cout << "Number is palin!" << endl;
            if (len % 2 == 0)
            {
                x.arr[len / 2 - 1]++;
                x.arr[len / 2]++;
                cout << x.arr<<endl;
                continue;
            }
            else
            {
                x.arr[len / 2]++;
                cout << x.arr<<endl;
                continue;
            }
        }


        for (long int i = (len-1) / 2; i >= 0; --i)
        {
            if (len % 2 == 1 && i==(len-1)/2)
            {
                continue;
            }
            else
            {
                if (x.arr[i] > x.arr[len - i - 1])
                {
                    x.arr[len - i - 1] = x.arr[i];
                    for (long int j = i - 1; j >= 0; --j)
                    {
                        x.arr[len - j - 1] = x.arr[j];
                    }
                    break;
                }
                else if (x.arr[i] == x.arr[len - i - 1])
                {
                    ;
                }
                else
                {
                    if (len % 2 == 1)
                    {
                        if (x.arr[len / 2] == '9')
                        {
                            x.arr[len / 2] = '0';
                            int temp = len / 2 - 1;
                            while (x.arr[temp] == '9')
                            {
                                x.arr[temp] = '0';
                                temp--;
                            }
                            x.arr[temp]++;
                        }
                        else
                        {
                            x.arr[len / 2]++;
                        }
                        for (long int j = len / 2 + 1; j < len; j++)
                        {
                            x.arr[j] = x.arr[len - j - 1];
                        }
                        break;
                    }
                    else
                    {
                        if (x.arr[len / 2 - 1] == '9')
                        {
                            x.arr[len / 2 - 1] = '0';
                            int temp = len / 2 - 2;
                            while (x.arr[temp] == '9')
                            {
                                x.arr[temp] = '0';
                                temp--;
                            }
                            x.arr[temp]++;
                        }
                        else
                        {
                            x.arr[len / 2 - 1]++;
                        }
                        for (long int j = len / 2 ; j < len; j++)
                        {
                            x.arr[j] = x.arr[len - j - 1];
                        }
                        break;
                    }
                }                
            }
        }
        if (k == 0)
        {
            cout << x.arr;
        }
        else
        {
            cout << x.arr << endl;
        }
    }
    _getch();
    return 0;
}