#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main ()
{
    int total_voters = 0, input, counter = 0;
    cin >> total_voters;
    cin >> input;
    total_voters += input;
    cin >> input;
    total_voters += input;

    vector<int> voters (total_voters);
    vector<int> final_list (total_voters);

    for (int i = 0; i < total_voters; ++i)
    {
        cin >> voters[i];
    }
    sort (voters.begin(), voters.end());
    for (int i = 0; i < total_voters; ++i)
    {
        if (voters[i] == voters [i+1])
        {
            final_list[counter] = voters[i];
            ++counter;
            if (voters[i+1] == voters [i+2])
            {
                i += 2;
            }
            else
            {
                ++i;
            }

        }
        else
        {
            continue;
        }

    }
    cout << counter << endl;
    for (int i = 0; i < counter; ++i)
    {
        cout << final_list[i] << endl;
    }
    return 0;

}

