#include <iostream>
using namespace std;

int values [2500][2500], calc_values [2500][2500];
bool checked [2500][2500];
int n;


void go_from_position (int row, int column) //assuming right most is the single robot
{
    int calc;
    if ((row == n-1) && (column == 0))
    {
        return;
    }
    else if ((row == n) && column == 1)
    {
        return;
    }
    else if (checked[row][column])
    {
        return;
    }
    if (row == n)
    {
        calc = values[row][column-1] + values[n-column+1][n-row];
        cout << "calc = " << calc << " " << row << " " << column << endl;
        if (calc > calc_values[row][column-1])
        {
            calc_values[row][column-1] = calc + calc_values[row][column];
        }
        go_from_position(row, column-1);
    }
    else if ( column == n)
    {
        calc = values[row+1][column] + values[n-column][n-row+1];
        cout << "calc = " << calc << " " << row  << " " << column << endl;
        if (calc > calc_values[row+1][column])
        {
            calc_values[row+1][column] = calc + calc_values[row][column];
        }
        go_from_position(row+1, column);
    }
    else
    {
        calc = values[row][column-1] + values[n-column+1][n-row];
        cout << "calc = " << calc << " " << row << " " << column << endl;
    	if (calc > calc_values[row][column-1])
   	{
        	calc_values[row][column-1] = calc + calc_values[row][column];
    	}
    	calc = values[row+1][column] + values[n-column][n-row+1];
    	cout << "calc = " << calc << " " << row << " " << column << endl;
    	if (calc > calc_values[row+1][column])
    	{
        	calc_values[row+1][column] = calc + calc_values[row][column];
    	}
    	go_from_position(row+1, column);
    	go_from_position(row, column-1);

    }
    checked[row][column] = true;

    return;
}


int main ()
{
    cin >> n;
    --n;
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j<=n ; ++j)
        {
            cin >> values[i][j];
        }

    }
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j<=n ; ++j)
        {
            calc_values[i][j] = -100000;
        }

    }
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j<=n ; ++j)
        {
            checked[i][j] = false;
        }

    }
    calc_values [0][n] = values[0][n];
    calc_values [0][0] = values[0][0];
    go_from_position(0,n);
    if (calc_values[n-1][0] > calc_values[n][1])
    {
        cout << values[n][0] + calc_values[n-1][0];
    }
    else
    {
        cout << values[n][0] + calc_values[n][1];
    }
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j<=n ; ++j)
        {
            cout << calc_values[i][j] << " ";
        }
        cout << endl;

    }
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j<=n ; ++j)
        {
            cout << values[i][j] << " ";
        }
        cout << endl;

    }
    return 0;

}
