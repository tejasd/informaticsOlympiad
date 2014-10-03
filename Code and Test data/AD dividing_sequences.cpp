#define MAXINT 10000

#include <iostream>
using namespace std;

int no_of_members;
int sequence [MAXINT];
int Max_best [MAXINT];

int Maximum (int num1, int num2)
{
    if (num1>num2)
    {
        return num1;
    }
    return num2;
}

int best (int index)
{
    int max = 1;
    if (Max_best[index] != 0)
    {
        return Max_best [index];
    }
    else if (index == 0)
    {
        return 1;
    }
    else
    {

        for (int i = 0; i < index; ++i)
        {
            if (sequence[index] % sequence [i] == 0)
            {
                max = Maximum(max,best(i)+1);
            }
        }
    }
    return max;
}

int main ()
{

    int Maxi = 0;



    cin >> no_of_members;
    for (int i = 0; i < no_of_members; ++i)
    {
        Max_best[i] = 0;
    }
    for (int i = 0; i < no_of_members; ++i)
    {
        cin >> sequence[i];

    }
    for (int i = 0; i < no_of_members; ++i)
    {
        Max_best[i] = best(i);
    }
    for (int i = 0; i < no_of_members; ++i)
    {
        if (Max_best[i] > Maxi)
        {
            Maxi = Max_best[i];
        }
    }

    cout << Maxi << endl;

    return 0;

}
