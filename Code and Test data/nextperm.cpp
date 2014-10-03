#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector <int> perm;

int main ()
{
    int n, k;
    cin >> n >> k;
    perm.resize(n);

    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> perm[j];
        }
        next_permutation(perm.begin(), perm.end());
        for (int j = 0; j < n; ++j)
        {
            cout << perm[j] << " ";
        }
        cout << endl;
    }

    return 0;
}
