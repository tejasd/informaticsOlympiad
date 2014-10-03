#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;




int main ()
{
    int no_of_blocks, li, bi, counter = 0;
    cin >> no_of_blocks;
    vector<int> indraneelsblocks (no_of_blocks);
    for (int i = 0; i < no_of_blocks; ++i)
    {
        cin >> li >> bi;
        if (li > bi)
        {
            indraneelsblocks[i] = bi;
        }
        else
        {
            indraneelsblocks[i] = li;
        }


    }
    sort (indraneelsblocks.begin(), indraneelsblocks.end());

    for (int i = 0; i < no_of_blocks; ++i)
    {
        if (indraneelsblocks[i] > counter)
        {
            ++counter;
        }
    }

    cout << counter << endl;

    return 0;

}
