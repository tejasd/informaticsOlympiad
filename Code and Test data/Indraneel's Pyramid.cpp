#include <iostream>
#include <algorithm>
using namespace std;

int main ()
{
    int a,b,m,counter;
    int indraneel [1000000];
    cin >> m;
    for (int c = 0; c < m; ++c)
    {
        cin >> a >> b;
        if (a > b)
        {
            indraneel[c] = b;
        }
        else
        {
            indraneel[c] = a;
        }
    }
    sort (indraneel,indraneel+m);

    //temp = 0;
    counter = 0;

    for (int c = 0; c < m; ++c)
    {
        if (indraneel[c] > counter)
        {
            ++counter;

        }
    }
    cout << counter;
    return 0;
}
