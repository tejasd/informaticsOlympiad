#include <iostream>
using namespace std;


int array [10000][10000];

//the function to calculate the best n*n grid in a given rectangle of array

int find_max_grid (int top_column,int top_row,int bottom_column,int bottom_row) //top left and bottom right this is array numbering, NOT normal numbering
{
    bool flag1;
    int max_n;
    int max_value = -10000000;
    int current_calculated_value;
    if ((bottom_row-top_row+1) > (bottom_column-top_column+1))//finding what is max_n
    {
        max_n = bottom_row-top_row+1;
    }
    else
    {
        max_n = bottom_column-top_column+1;
    }
    for (int i = 1; i <= max_n; ++i)//n loop which determines n*n which value is taken
    {
        for (int column = top_column+i-1; column <= bottom_column; ++column)//the column loop
        {
            for (int row = top_row+i-1;row <= bottom_row;++row)//the row loop
            {
                flag1 = true;
                current_calculated_value = array[row][column];
                if (row-i>=0)
                {
                    current_calculated_value -= array[row-i][column];
                }
                else
                {
                    flag1 = false;
                }
                if (column - i >= 0)
                {
                    current_calculated_value -= array[row][column-i];
                }
                else
                {
                    flag1 = false;
                }
                if (flag1)
                {
                    current_calculated_value += array[row-i][column-i];
                }
                if (current_calculated_value > max_value)
                {
                    max_value = current_calculated_value;
                }
            }
        }
    }
    return max_value;
}

int main ()
{

    bool flag;
    int total_rows,total_columns,current_value;

    cin >> total_rows >> total_columns;
    for (int rows = 0; rows < total_rows; ++rows)
    {
        for (int columns = 0; columns < total_columns; ++columns)
        {
            flag = true;
            cin >> current_value;
            if (current_value == 0)
            {
                current_value = -88067155;

            }
            array [rows][columns] = current_value;
            if (columns-1 >= 0)
            {
                array[rows][columns] += array[rows][columns-1];
            }
            else
            {
                flag = false;
            }
            if (rows -1 >= 0)
            {
                array [rows][columns] += array[rows-1][columns];
            }
            else
            {
                flag = false;
            }
            if (flag)
            {
                array[rows][columns] -= array[rows-1][columns-1];
            }
        }
    }
    cout << find_max_grid(0,0,total_columns-1,total_rows-1) << endl;
    return 0;
}
