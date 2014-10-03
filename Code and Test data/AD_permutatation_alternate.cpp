#include <iostream>
using namespace std;

int initial_sequence [100000];
int final_permutation [100000];

int main ()
{
    int no_of_numbers,temp,counter;
    cin >> no_of_numbers;
    for (int i = 0; i < no_of_numbers; ++i)
    {
        cin >> initial_sequence[i];
    }
    for (int i = 0; i < no_of_numbers; ++i)
    {
        final_permutation[i] = -1;
    }
    for (int i = no_of_numbers-1; i >= 0; --i)
    {
        counter = 0;
        temp = initial_sequence[i];
        for (int j = no_of_numbers-1; j >= 0; --j)
        {
            if (counter == temp)
            {
                if (final_permutation[j] == -1)
                {
                    final_permutation[j] = i+1;
                    break;
                }
            }
            else
            {
                if (final_permutation[j] == -1)
                {
                    ++counter;
                }
            }
        }

    }
    for (int i = 0; i < no_of_numbers; ++i)
    {
        cout << final_permutation[i] << " ";
    }
    return 0;
}
