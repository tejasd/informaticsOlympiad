#include <iostream>
#include <vector>
using namespace std;

vector<int> merchants (45000);

int findrank (int wealth, int no_of_merchants) //also moves to respective place in array
{
    int left, right, pivot;
    right = no_of_merchants; //no_of_merchants -1 basically i
    left = 0;

    if (wealth < merchants[no_of_merchants])
    {
        merchants[no_of_merchants+1] = wealth;
        return no_of_merchants+1;
    }
    else if (wealth > merchants[0])
    {
        for (int i = no_of_merchants; i >= 0; --i)
        {
            merchants[i+1] = merchants[i];
        }
        merchants[0] = wealth;
        return 0;
    }
    else
    {
        for (;;)
        {
            pivot = (left+right)/2;
            if (merchants[pivot] > wealth)
            {
                if (merchants[pivot+1] < wealth)
                {
                    for (int i = no_of_merchants; i >= pivot+1; --i)
                    {
                        merchants[i+1] = merchants[i];
                    }
                    merchants[pivot+1] = wealth;
                    return pivot+1;
                }
                else
                {
                    left = pivot;
                }
            }
            else
            {
                if (merchants[pivot-1] > wealth)
                {
                    for (int i = no_of_merchants; i >= pivot; --i)
                    {
                        merchants[i+1] = merchants[i];
                    }
                    merchants[pivot] = wealth;
                    return pivot;
                }
                else
                {
                    right = pivot;
                }
            }
        }
    }
}


int main ()
{
    int no_of_mercs, wealth1;
    cin >> no_of_mercs;
    cout << "1" << endl;
    cin >> merchants[0];

    for (int i = 1; i < no_of_mercs; ++i)
    {
        cin >> wealth1;
        cout << findrank(wealth1, i) + 1 << endl;
    }
    return 0;
}
