#include <iostream>
#include <algorithm>
using namespace std;
bool even_odd; //even is 0, odd is 1

long long int earthworms [20];
long long int no_of_leaves;
long long int total = 0;
int no_of_earthworms, no_of_selections;


long long int gcd (long long int num1, long long int num2)
{
    long long int temp2;
    for (;;)
    {
        if (num1%num2 == 0)
        {
            break;
        }
        else
        {
            temp2 = num1%num2;
            num1 = num2;
            num2 = temp2;
        }

    }
    return num2;
}


long long int lcm (int num1, int num2)
{
    return (num1*num2)/gcd (num1, num2);
}

void inclusion_exclusion (long long int no_of_remaining_selections,long long int from_index, long long int previous_lcm)
{
    if (no_of_remaining_selections == 1)
    {
        if (no_of_selections%2==0)
        {
            even_odd = 0;
        }
        else
        {
            even_odd = 1;
        }
        for (int i = from_index; i < no_of_earthworms; ++i)
        {
            if (even_odd)
            {
                total += (1+((no_of_leaves-1)/(lcm(previous_lcm,earthworms[i]))));

            }
            else
            {
                total -= (1+((no_of_leaves-1)/(lcm(previous_lcm,earthworms[i]))));
            }

        }
    }
    else
    {
        for (int i = from_index; i < no_of_earthworms-no_of_remaining_selections+1; ++i)
        {
            inclusion_exclusion(no_of_remaining_selections-1, i+1, lcm(previous_lcm, earthworms[i]));
        }
    }
}



int main ()
{
    cin >> no_of_leaves >> no_of_earthworms;
    for (int i = 0; i < no_of_earthworms; ++i)
    {
        cin >> earthworms[i];
    }
  //  sort (earthworms, &earthworms[no_of_earthworms-1]);


    for (int i = 1; i <= no_of_earthworms; ++i)
    {
        no_of_selections = i;
        inclusion_exclusion(i,0,1);
    }


    cout << no_of_leaves-total << endl;
    return 0;

}
