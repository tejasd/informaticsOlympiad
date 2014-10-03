#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <vector>

using namespace std;



bool compare_ints(const int &a, const int &b)
{
    return abs(a) < abs(b);
}

int main ()
{
    vector <int> people;
    int number_of_entries, max_counter, counter, people1, people2;
    cin >> number_of_entries;
    for (int i = 0; i < number_of_entries *2 ; i=i+2)
    {
        cin >> people1 >> people2;
        people.push_back(people1);
        people.push_back(-people2);

    }
  std::sort (people.begin(),people.end(), compare_ints);

    //main function
    max_counter = 0;
    counter = 0;

    for (int i = 0; i < number_of_entries*2; ++i)
    {
        if (people[i] > 0)
        {
            ++counter;
            if (max_counter < counter)
            {
                max_counter = counter;
            }
        }
        else
        {
            --counter;
        }
    }
    cout << max_counter << endl;
    return 0;
}
