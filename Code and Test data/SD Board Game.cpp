#include <iostream>
#include <vector>
using namespace std;

int main ()
{
    int length_of_board, dice, score = 1, position = 0, number_of_throws;
    char symbol;

    cin >> length_of_board;
    vector<int> board (length_of_board);

    cin >> number_of_throws;



    for (int i = 0; i < length_of_board; ++i)
    {

        cin >> symbol;
        if (symbol == '+')
        {
            board[i] = 1;
            //cout << "plus\n";
        }
        else
        {
            board[i] = 0;
        }
    }
    /*cout << "debug\n";
    for (int i = 0; i < length_of_board; ++i)
    {
        cout << board[i] << endl;
    }*/

    for (int i = 0; i < number_of_throws; ++i)
    {
        cin >> dice;
        if (board[position]==1)
        {
            if ((position + dice)<length_of_board)
            {
                position += dice;
            }
        }
        else
        {
            if ((position - dice)>=0)
            {
                position -= dice;
            }
        }
        if (position == 0)
        {
            ++score;
        }
    }
    cout << score << endl;
    return 0;





}
