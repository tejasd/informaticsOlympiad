#define MAXINT 1000001

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector <int> grouped_profits;
vector <int> no_of_grouped;

int profits [MAXINT];
int no_of_stations,k;

bool sign (int num)//returns 1 if positive, 0 if negative
{
    if (num < 0)
    {
        return 0;
    }
    return 1;
}


int k_window_method (int k)
{
    int sum = 0,max;
    for (int i = 0; i < k; ++i)
    {
        sum += profits[i];
    }
    max = sum;

    for (int i = 0; i < no_of_stations-k; ++i)
    {
        sum -= profits[i];
        sum += profits[i+k];
        if (sum > max)
        {
            max = sum;
        }
    }
    return max;
}


int main ()
{
    int total, counter, first_element,max = 0; //first element is the index of the vector which is first positive
    cin >> no_of_stations >> k;
    for (int i = 0; i < no_of_stations; ++i)
    {
        cin >> profits[i];
    }
    counter = 1;
    total = profits[0];
    for (int i = 1; i < no_of_stations; ++i)
    {
        if (sign(profits[i-1]) == sign(profits [i]))
        {
            total += profits[i];
            ++counter;
        }
        else
        {
            grouped_profits.push_back(total);
            no_of_grouped.push_back(counter);
            counter = 1;
            total = profits[i];
        }
    }
    if (sign(grouped_profits[0]))
    {
        first_element = 0;
    }
    else
    {
        first_element = 1;
    }
    max = k_window_method(k);
   // cout << "max is " << max << endl;
    total = grouped_profits[first_element];
    counter = no_of_grouped[first_element];
    for (int i = first_element; i < no_of_stations-2; )
    {
        if (fabs(grouped_profits[i+1]) < fabs(grouped_profits[i+2]))
        {
            total += grouped_profits[i+1] + grouped_profits[i+2];
            counter += no_of_grouped[i+1] + no_of_grouped[i+2];
        }
        else
        {
            if (counter >= k)
            {
                if (total > max)
                {
                    max = total;
                }
            }
            counter = no_of_grouped[i+2];
            total = grouped_profits[i+2];

        }
        i = i+2;
    }




    cout << max << endl;

    return 0;

}
