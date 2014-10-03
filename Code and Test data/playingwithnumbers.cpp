#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
vector<int> forbidden;


int final, final_steps = 999999999, no_of_forbidden;


void build_tree (int num, int placevalue, int how, int tym) //num is the root number coz this is recursive function, placevalue - which number was altered in the last call, how how was the placevalue number altered in last call
{
    if (num == final)
    {
        if (tym < final_steps)
        {
            final_steps = tym;
            return;
        }
    }
    else
    {
        if (binary_search(forbidden.begin(), forbidden.end(), num))
            return;
    }
    //last digit
    if (placevalue == 1 && how == 1)//+1
    {
        placevalue = placevalue;
    }
    else
    {
        if (num % 10 == 9)
        {
            build_tree(num-9, 1, 1, tym+1);

        }
        else
        {
            build_tree(num+1, 1, 1, tym+1);
        }

    }
    //-1
    if (placevalue == 1 && how == -1)
    {
        placevalue = placevalue;
    }
    else
    {
        if (num % 10 == 0)
        {
            build_tree(num+9, 1, -1, tym+1);
        }
        else
        {
            build_tree(num-1, 1, -1, tym+1);
        }

    }
    //10th place
    if (placevalue == 2 && how == 1)//+1
    {
        placevalue = placevalue;
    }
    else
    {
        if ((num/10)%10 == 9)
        {
            build_tree(num-90, 2, 1, tym+1);
        }
        else
        {
            build_tree(num+10, 2, 1, tym+1);
        }

    }
    //-1
    if (placevalue == 2 && how == -1)
    {
        placevalue = placevalue;
    }
    else
    {
        if ((num/10)%10 == 0)
        {
            build_tree(num+9, 2, -1, tym+1);
        }
        else
        {
            build_tree(num-10, 2, -1, tym+1);
        }

    }
    //100th place
    if (placevalue == 3 && how == 1)//+1
    {
        placevalue = placevalue;
    }
    else
    {
        if ((num/100)%10 == 9)
        {
            build_tree(num-900, 3, 1, tym+1);
        }
        else
        {
            build_tree(num+100, 3, 1, tym+1);
        }

    }
    //-1
    if (placevalue == 2 && how == -1)
    {
        placevalue = placevalue;
    }
    else
    {
        if ((num/100)%10 == 0)
        {
            build_tree(num+900, 3, -1, tym+1);
        }
        else
        {
            build_tree(num-100, 3, -1, tym+1);
        }

    }
    //1000th place
    if (placevalue == 4 && how == 1)//+1
    {
        placevalue = placevalue;
    }
    else
    {
        if ((num/1000)%10 == 9)
        {
            build_tree(num-9000, 4, 1, tym+1);
        }
        else
        {
            build_tree(num+1000, 4, 1, tym+1);
        }

    }
    //-1
    if (placevalue == 4 && how == -1)
    {
        placevalue = placevalue;
    }
    else
    {
        if ((num/1000)%10 == 0)
        {
            build_tree(num+9000, 4, -1, tym+1);
        }
        else
        {
            build_tree(num-1000, 4, -1, tym+1);
        }

    }
    return;
}


int main ()
{
    int no_of_test_cases, initial_number, inputint;
    string input;
    cin >> no_of_test_cases;
    getline (cin, input);

    for (int testcase = 0; testcase < no_of_test_cases; ++testcase)
    {
        forbidden.clear();
        cin >> initial_number;
        cin >> final;
        cin >> no_of_forbidden;

        for (int i = 0; i < no_of_forbidden; ++i)
        {
            cin >> inputint;
            forbidden.push_back(inputint);
        }
        sort(forbidden.begin(), forbidden.end());
        build_tree(initial_number, 0, 0, 0);
        cout << final_steps << endl;

    }
    return 0;
}














