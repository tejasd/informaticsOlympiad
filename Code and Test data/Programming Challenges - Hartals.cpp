#include <iostream>

using namespace std;

int test_cases, no_of_pp, days, pp_h[100], counter, test_case_counter;
char days_array[3650];


int main()
{

    cin >> test_cases;
    for (test_case_counter = 0; test_case_counter < test_cases ; ++test_case_counter)
    {
        counter = 0;
        //initialise character array to zero
        for (int t = 0; t < days; ++t)
        {
            days_array[t] = '0';
        }
        cin >> days;
        cin >> no_of_pp;
        for (int i = 0; i < no_of_pp; ++i)//input the h's
        {
            cin >> pp_h[i];
        }
        //make all days there is hartal 1
        for (int a = 0; a < no_of_pp; ++a)
        {

            for (int j = pp_h[a] - 1; j < days; j = j + pp_h[a])
            {
                days_array[j] = '1';
                //debug
                //cout << j << " is the days marked\n";
            }
        }
        //for fridays
        for (int b = 5; b < days; b = b+7)
        {
            days_array[b] = '0';
        }
        //for saturdays
        for (int c = 6; c < days; c = c+7)
        {
            days_array[c] = '0';
        }
        for (int d = 0; d < days; ++d)
        {
            if (days_array[d] == '1')
            {
                ++counter;
            }
        }
        cout << counter << "\n";

    }
    return 0;
}
