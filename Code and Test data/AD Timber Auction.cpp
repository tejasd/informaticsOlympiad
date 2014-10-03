#define MAX_ROW 1000
#define MAX_COLUMN 1000


#include <iostream>
using namespace std;

int tree_volume [MAX_ROW][MAX_COLUMN];


long long int top (int row,int column)
{
    if (row-1 < 0)
    {
        return 0;
    }
    else
    {
        return tree_volume [row-1][column];
    }
}
long long int left (int row,int column)
{
    if (column-1 < 0)
    {
        return 0;
    }
    else
    {
        return tree_volume [row][column-1];
    }
}
long long int top_left_corner (int row, int column)
{
    if (row-1 < 0 || column -1 < 0)
    {
        return 0;
    }
    else
    {
        return tree_volume [row-1][column - 1];
    }
}

int main ()
{
    int total_rows, total_columns, input, x1, x2, y1, y2;
    cin >> total_rows >> total_columns;
    for (int rows = 0; rows < total_rows ; ++rows)
    {
        for (int columns = 0; columns < total_columns; ++columns)
        {
            cin >> input;
            tree_volume[rows][columns] = input + left(rows,columns) + top(rows, columns) - top_left_corner(rows, columns);
        }
    }
   /* cout << "here is how it looks\n";
    for (int i = 0; i < total_rows; ++i)
    {
        for (int j = 0; j < total_columns; ++j )
        {
            cout << tree_volume[i][j] << " ";
        }
        cout << endl;
    }*/
    cin >> input;
    for (int i = 0; i < input; ++i)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        --x1;
        --x2;
        --y1;
        --y2;
        int total = 0;
        total += tree_volume[x2][y2];
        if (x1-1 != -1)
        {
            total -= tree_volume[x1-1][y2];
        }
        if (y2-1 != -1)
        {
            total -= tree_volume[x2][y1-1];
        }
        if (x1-1 != -1 && y1-1 != -1 )
        {
            total += tree_volume[x1-1][y1-1];
        }
        cout << total << endl;
        total = 0;
    }
    return 0;
}
