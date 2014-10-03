#include <iostream>
using namespace std;

int main ()
{
    int temp, before, current, n;
    before = 1;
    current = 2;
    cin >> n;
    if (n == 1)
    {
        cout << before;
    }
    else if (n == 2)
    {
        cout << current;
    }
    else
    {
        for (int i = 2; i < n; ++i)
        {
            temp = current;
            current = current+before;
            before = temp;
            if (current > 15746)
            {
                current -= 15746;
            }
        }
        cout << current << endl;
    }
    return 0;

}
