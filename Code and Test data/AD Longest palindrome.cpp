#include <iostream>
#include <string>
using namespace std;

int main ()
{
    string data;
    int length, left, right;
    cin >> length;
    cin >> data;
    for (int j = length; j > 1; --j) //length of subword
    {
        for (int i = 0; i < length-j; ++i)
        {
            left = i;
            right = length-j+i-1;
            if ((j%2)==0)
            {
                cout << "entered even for j = " << j << endl;
                for (;;)
                {
                    if (left == right -1)
                    {
                        break;
                    }
                    if (data[left] != data[right])
                    {
                        break;
                    }
                    else
                    {
                        ++left;
                        --right;
                    }
                }

                if (left == right-1)
                {
                    cout << j << endl;
                    for (int a = i; a != length-j+i; ++i)
                    {
                        cout << data[a];
                    }
                    return 0;
                }
            }
            else //odd
            {
                cout << "entered odd for j = " << j << endl;
                for (;;)
                {
                    if (left == right-2)
                    {
                        break;
                    }
                    if (data[left] != data[right])
                    {
                        break;
                    }
                    else
                    {
                        ++left;
                        --right;
                    }
                }
                if (left == right-2)
                {
                    cout << j << endl;
                    for (int a = i; a != length-j+i; ++i)
                    {
                        cout << data[a];
                    }
                    return 0;
                }
            }
        }
    }
    cout << "0" << endl;
    cout << data[0];
    return 0;
}
