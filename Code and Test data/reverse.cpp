#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main ()
{
    //input

    int n, word_start, word_end, length;
    cin >> n;

    vector<string> line(n);

    for (int i = 0; i < n; ++i)
    {
        getline (cin, line[i]);
    }

    //input done

    for (int i = n-1; i >= 0; --i)
    {
        length = line[i].length();
        for (int j = length-1; j >= 0; --j)
        {
            if (line[i][j] == '.')
            {
                word_end = j-1;
            }
            else if (line[i][j] == ' ' && line[i][j+1] != ' ')
            {
                word_start = line[i][j+1];

            }
        }

    }


}
