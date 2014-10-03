#include <iostream>
#include <algorithm>
using namespace std;

long long int no_of_leaves, counter = 0;
int no_of_bugs, bug_lengths [20];

int main ()
{
    cin >> no_of_leaves >> no_of_bugs;
    for (int i = 0; i < no_of_bugs; ++i)
    {
        cin >> bug_lengths [i];
        if (bug_lengths[i] == 1)
        {
            cout << "0\n";
            return 0;
        }
    }
    sort (bug_lengths, &bug_lengths[no_of_bugs-1]);
    for (long long int i = 1; i < no_of_leaves; ++i)
    {
        for (int j = 0; j < no_of_bugs; ++j)
        {
            if (i % bug_lengths[j] == 0)
            {
                ++counter;
                break;
            }
            else
            {
                continue;
            }
        }
    }
    cout << no_of_leaves - counter - 1 << endl;
    return 0;

}
