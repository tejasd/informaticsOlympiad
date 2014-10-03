#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class givendata
{
    public:
    int nums [50];
    int total;
};

bool myfunction (givendata a, givendata b);

int main ()
{
    int no_of_rows, input;

    cin >> no_of_rows;

    givendata rows[1000];

    for (int i = 0; i < no_of_rows; ++i)
    {
        for (int j = 0;;)
        {
            cin >> input;
            if (input == -1)
            {
                rows[i].total = j;
                break;
            }
            else
            {
                rows[i].nums[j] = input;
                ++j;
            }

        }
    }

    sort (rows, rows+no_of_rows, myfunction);

    //output

    for (int i = 0; i < no_of_rows; ++i)
    {
        for (int j = 0; j < rows[i].total; ++j)
        {
            cout << rows[i].nums[j] << " ";
        }
        cout << endl;
    }

    return 0;

}


bool myfunction (givendata a, givendata b)
{
    int counter;

    if (a.total < b.total)
    {
        counter = a.total;
    }
    else
    {
        counter = b.total;
    }

    for (int i = 0; i < counter; ++i)
    {
        if (a.nums[i] < b.nums[i])
        {
            return true;
        }
        else if (a.nums[i] > b.nums[i])
        {
            return false;
        }
        else
        {
            continue;
        }
    }
    return (a.total < b.total);

}
