#include <iostream>
using namespace std;

bool leafs [1000000000];
int bugs[20];
long long int no_of_leaves, counter = 0;
int no_of_bugs;

int main ()
{
    cin >> no_of_leaves >> no_of_bugs;
    for (int i = 0; i < no_of_bugs; ++i)
    {
        cin >> bugs[i];
    }
    //initi to false false is not eaten
    for (long long int num = 0; num < no_of_leaves; ++num)
    {
        leafs[num] = false;
    }
    //iterations to mark the array blocks true if eaten
    for (int i = 0; i < no_of_bugs; ++i)
    {

        for (long long int j = 0; j < no_of_leaves;)
        {
            leafs[j] = true;
            j = j + bugs[i];
        }
    }
    for (long long int num = 0; num < no_of_leaves; ++num)
    {
        if (leafs[num] == false)
        {
            ++counter;
        }
    }
    cout << counter << endl;
    return 0;
}
