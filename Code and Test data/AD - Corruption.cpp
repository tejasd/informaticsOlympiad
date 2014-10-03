#include <iostream>
#include <queue>
using namespace std;

priority_queue<long> court;

int main()
{
    long king, citizens,current;
    cin >> citizens >> king;
    for (int i = 0; i < citizens+king; ++i)
    {
        cin >> current;
        if (current == -1)
        {

            if (court.empty())
            {
                continue;
            }
            else
            {
                cout << court.top() << endl;
                court.pop();
            }
        }
        else
        {
            court.push(current);
        }
    }
    return 0;
}

