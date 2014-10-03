// Averages - Advanced Division

#include <iostream>
#include <algorithm>
using namespace std;

int main ()
{
    int integers[10000], counter = 0;
    bool integersbool[10000];
    int no_of_integers;
    cin >> no_of_integers;
    for (int i = 0; i < no_of_integers; ++i)
    {
        cin >> integers[i];
    }
    for (int i = 0; i < no_of_integers; ++i)
    {
        integersbool[i] = false;
    }
    sort (integers, integers+no_of_integers);

    //check for duplicates
    /*for (int i = 0; i < (no_of_integers-1); ++i)
    {
        if (integers[i] == integers[i+1])
        {
            if (integersbool[i] == true)
            {
                continue;
            }
            else
            {
                integersbool[i] = true;
                ++counter;
            }
            integersbool[i+1] = true;
            ++counter;
        }
    }*/

    for (int i = 1; i < no_of_integers-1; ++i)
    {
        /*if (integersbool[i] == true)
        {
            i == i;
        }*/
        //else
        //{


            for (int left = i-1, right = i+1; left != -1 && right != no_of_integers;)
            {
                if (((integers[left]+integers[right])/2) > integers[i])
                {
                    --left;
                }
                else if (((integers[left]+integers[right])/2) < integers[i])
                {
                    ++right;
                }
                else
                {
                    ++counter;
                    break;
                }
            }
        //}
    }
    cout << counter << endl;
    return 0;
}
