#include <iostream>
using namespace std;

int final_permutation [100000];
int initial_sequence [100000];
int already_occupied [100002];

int find_position (int num, int * sorted_array, int right) //here array will be sorted in reverse order
{
    int left, pivot;
    left = 0;
    if (num < sorted_array[right])
    {
           return right+1;
    }
    else if (num > sorted_array[0])
    {
        return 0;
    }

    for (;;)
    {
        pivot = int (long(right + left )/2);

        if (sorted_array[pivot] == num)
        {
            return pivot + 1;
        }
        else if (sorted_array[left] == num)
        {
            return left+1;
        }
        else if (sorted_array[right] == num)
        {
            return right + 1;
        }
        else if ((right - left) == 1)
        {
            return right;
        }
        else if (num < sorted_array[pivot])
        {
            left = pivot;
        }
        else if (num > sorted_array[pivot])
        {
            right = pivot;
        }
    }


}

int main ()
{
    int no_of_numbers, first;
    cin >> no_of_numbers;
    for (int i = 0; i < no_of_numbers; ++i)
    {
        cin >> initial_sequence[i];
    }
    first = no_of_numbers - initial_sequence[no_of_numbers-1] - 1;
    final_permutation[first] = no_of_numbers; //putting the leftmost element

    if (no_of_numbers - (2 + initial_sequence[no_of_numbers-2])  > first )
    {
        already_occupied[0] = no_of_numbers - (1 + initial_sequence[no_of_numbers-2]);
        already_occupied[1] = first;
        final_permutation[already_occupied[0]] = no_of_numbers-1;
    }
    else
    {
        already_occupied [0] = first;
        already_occupied [1] = no_of_numbers - (2 + initial_sequence[no_of_numbers-2]);
        final_permutation[already_occupied[1]] = no_of_numbers -1;

    }
    cout << "Already Occupied Array ";
                for (int k = 0; k < 2; ++k)
                {
                    cout << already_occupied[k] << " ";
                }
                cout << "\n";

                for (int i = 2; i < no_of_numbers; ++i)
                {
                    int last,original,current;
                    original = no_of_numbers - initial_sequence[no_of_numbers-i-1] - 1;
                    last = original;
                    for (;;)
                    {
                        current = find_position(original,already_occupied,i-1);
                        if (last > original - current)
                        {
                            last = original - current;
                        }
                        else
                        {
                            cout << "Position of " << no_of_numbers-i << " is " << last << endl;
                            final_permutation[last] = no_of_numbers-i;
                            for (int j = i; j > current; --j) //problematic
                            {
                                already_occupied[j] = already_occupied[j-1];
                            }
                            already_occupied[current] = last;
                            cout << "Already Occupied Array ";
                for (int k = 0; k <= i; ++k)
                {
                    cout << already_occupied[k] << " ";
                }
                cout << "\n";
                            break;

                        }
                    }
                }
    /*for (int i = 2; i < no_of_numbers; ++i)

        int last_position, current_position, original_position;
        original_position = last_position =  no_of_numbers - 1 - initial_sequence[no_of_numbers - (i+1)];
        for (;;)
        {
            cout << "entered infinit loop i = " << i << endl;

            current_position = find_position(last_position,already_occupied,i-1);
            if (last_position == original_position - current_position)
            {
                final_permutation[original_position - current_position] = i+1;
                for (int j = i; j > current_position; --j )
                {
                    already_occupied[j] = already_occupied[j - 1];
                }
                already_occupied[current_position] = original_position - current_position;
                cout << "Already Occupied Array ";
                for (int k = 0; k <= i; ++k)
                {
                    cout << already_occupied[k] << " ";
                }
                cout << "\n";
                break;
            }
            else
            {
                last_position = original_position - current_position;
            }
        }
    }*/

    //output
    for (int i = 0; i < no_of_numbers; ++i)
    {
        cout << final_permutation[i] << " ";
    }
    return 0;

}
