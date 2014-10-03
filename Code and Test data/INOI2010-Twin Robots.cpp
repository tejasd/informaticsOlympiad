#define MAXSIZE 10000

#include <iostream>
using namespace std;

int given_value [MAXSIZE][MAXSIZE], final_computation [MAXSIZE][MAXSIZE];
int value_at_that_point;

int main ()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> given_value[i][j];
        }
    }
    final_computation[n-1][0] = given_value[n-1][0] + given_value[n-1][n-1];
    //filling up the first column for computation
    for (int i = n-2; i >= 0; --i)
    {
        final_computation[i][0] = final_computation[i+1][0]+given_value[i][0] + given_value[n-1][i];
    }
    //filling up last row
    for (int i = 1; i < n; ++i)
    {
        final_computation[n-1][i] =final_computation[n-1][i-1]+ given_value[n-1][i] + given_value[n-1-i][n-1];
    }
    //now the actual calculations
    for (int i = 1; i < n; ++i)
    {
        for (int j = n-2; j >=0; --j)
        {
            value_at_that_point = given_value[j][i] + given_value[n-1-i][j];
            if (final_computation[j+1][i] > final_computation[j][i-1])
            {
                final_computation[j][i] = final_computation[j+1][i] + value_at_that_point;
                //cout << "Final Computation here at " << j << " " << i << " is " << final_computation[j][i] << endl;
            }
            else
            {
                final_computation[j][i] = final_computation[j][i-1] + value_at_that_point;
                //cout << "Final Computation here at " << j << " " << i << " is " << final_computation[j][i] << endl;
            }

        }
    }
   /* for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << given_value[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Line Break\n";
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << final_computation[i][j] << " ";
        }
        cout << endl;
    }*/

    cout << final_computation[0][n-1] << endl;

    return 0;
}
