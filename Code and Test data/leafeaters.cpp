#include <iostream>
#include <set>
using namespace std;

set <int> spoiltleaves;

int main ()
{
    long long int n;
    int k, input;

    spoiltleaves.insert(1);


    cin >> n >> k;


    for (int i = 0; i < k; ++i)
    {
        cin >> input;
        for (int j = 1+input; j <= n; j+= input)
        {
            spoiltleaves.insert(j);
        }

    }

    cout << n-spoiltleaves.size() << endl;
    return 0;
}
