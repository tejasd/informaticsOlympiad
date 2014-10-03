#include <iostream>
#include <algorithm>
using namespace std;

int no_of_numbers,threshold,previous,counter;
int blood_groups [1000001];

int main ()
{
    cin >> no_of_numbers >> threshold;
    for (int i = 0; i < no_of_numbers; ++i)
    {
        cin >> blood_groups[i];
    }
    sort (blood_groups, &blood_groups[no_of_numbers-1]);
    previous = blood_groups[0];
    counter = 1;
    for (int i = 1; i < no_of_numbers; ++i)
    {
        if ((blood_groups[i] - previous) >= threshold)
        {
            ++counter;
            previous = blood_groups[i];
        }
    }
    cout << counter << endl;
    return 0;
}

