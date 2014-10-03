#include <iostream>
#include <vector>
using namespace std;

unsigned long long int choose [10001][10001];
//vector < vector <unsigned long long int> > choose;

unsigned long long int nchooser (int n, int r)
{
    int a, b;
    if (choose[n][r] == 0)
    {
        a = nchooser(n-1,r);
        b = nchooser(n-1,r-1);
        choose[n][r] = a+b;
        return (a+b);
    }
    else
    {
        return choose[n][r];
    }
}

int main ()
{
    int n, one, zero, total;
    cin >> n;
    //choose.resize (n);
    one = n;
    zero = 0;
    total = 0;
    for (int i = 0; i <= n; ++i)//setting up of choose table
    {
        for (int j = 0; j <= n; ++j)
        {
            if (j == 0)
            {
                choose[i][j] = 1;
            }
            else if (i == j && i != 0)
            {
                choose[i][j] = 1;
            }
            else if (j == 1)
            {
                choose[i][j] = i;
            }
            else
            {
                choose[i][j] = 0;
            }
        }
    }
    if ((n%2)==0)
    {
        for (;;)
        {
            if (one < 0)
            {
                break;
            }
            total += nchooser(one+zero, one);
            //cout << total << endl;
            one -= 2;
            zero += 1;
            total = total%15746;
        }
    }
    else
    {
        for (;;)
        {
            if (one < 1)
            {
                break;
            }
            total += nchooser(one+zero, one);
            one -= 2;
            zero += 1;
            total %= 15746;
        }
    }
    //cout << total%15746 << endl;
    cout << nchooser(405,300) << endl;
    //cout << n << endl;
    return 0;

}
