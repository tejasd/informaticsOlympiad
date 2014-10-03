#include <iostream>
using namespace std;

int main ()
{
    int num;
    cin >> num;
    cout << num << " " << num<<endl;
    for (int i = 0; i < num; ++i)
    {
        for (int j = 0; j < num; ++j)
        {
            cout << j+1;
            if (j == num-1)
            {
                continue;

            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
