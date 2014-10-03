#include <iostream>
using namespace std;

int expected_profits [1000001];
int best [1000001];
int how_many_added [1000001];

int k_window_method (int k, int no_of_stations)
{
    int sum = 0,max = -999999999;
    for (int i = 0; i < k; ++i)
    {
        sum += expected_profits[i];
    }
    max = sum;

    for (int i = 0; i < no_of_stations-k; ++i)
    {
        sum -= expected_profits[i];
        sum += expected_profits[i+k];
        if (sum > max)
        {
            max = sum;
        }
    }
    return max;
}


int main ()
{
    int no_of_stations, k,max = 0, temp;
    cin >> no_of_stations >> k;
    for (int i = 0; i < no_of_stations; ++i)
    {
        cin >> expected_profits[i];
    }
    if (expected_profits[0] > 0)
    {
        best[0] = expected_profits[0];
        how_many_added[0] = 1;
    }
    else
    {
        best[0] = 0;
        how_many_added[0] = 0;
    }
    for (int i = 1; i < no_of_stations; ++i)
    {
        if (expected_profits[i]+best[i-1] > expected_profits[i])
        {
            best [i] = expected_profits[i] + best[i-1];
            how_many_added[i] = how_many_added[i-1] + 1;
        }
        else
        {


                best[i] = expected_profits[i];
                how_many_added[i] = 1;


        }
    }


    for (int i = 0; i < no_of_stations; ++i )
    {
        if (best[i] > max && how_many_added[i] >= k)
        {
            max = best[i];
        }
    }
    temp = k_window_method(k, no_of_stations);
    if (temp > max)
    {
        max = temp;
    }
    cout << max << endl;
    return 0;

}
