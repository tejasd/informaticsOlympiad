#include <iostream>
#include <string>
#include <sstream>
using namespace std;



bool is_palindrome (string num)
{
    //even length
    if ((num.length()%2)==0)
    {
        for (int i = 0; i < (num.length())/2; ++i)
        {
            if (num[i] == num[num.length()-i])
            {
                continue;
            }
            else
            {
                return 0;
            }
        }
        return 1;
    }
    else //odd length
    {
        for (int i = 0; i < ((num.length())/2)-1; ++i)
        {
            if (num[i] == num[num.length()-i])
            {
                continue;
            }
            else
            {
                return 0;
            }
        }
        cout << "it is palindrome\n";
        return 1;
    }
}


bool is_prime (string num)
{
    int a;
    stringstream (num) >> a;
    if (a%2==0)
    {
        return 0;
    }
    else
    {
        for (int i = (a/2)+1; i > 2; --i)
        {
            if (a%i==0)
            {
                return 0;
            }

        }
        cout << "it is prime\n";
        return 1;
    }
}





int main ()
{
    string number;
    int num;

    cin >> number;
    stringstream(number) >> num;
    if (is_palindrome(number) && is_prime(number))
    {
        cout << number << endl;
    }
    else
    {
        for (int i = num+1; ;++i)
        {
            stringstream(number) << i;
            if (is_palindrome(number) && is_prime(number))
            {
                cout << number;
            }

        }

    }
    return 0;


}
