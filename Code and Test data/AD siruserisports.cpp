#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class dates
{
    public:
    int start, end;
};

bool myfunction (dates i,dates j)
{
    if (i.end < j.end)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main ()
{
    int total_events, count_end, max_events = 0, blocked_till = 0;
    cin >> total_events;
    vector<dates> siruseri (total_events);
    for (int i = 0; i < total_events; ++i)
    {
        cin >> siruseri[i].start;
        cin >> count_end;
        siruseri[i].end = siruseri[i].start + count_end - 1;
    }
    sort (siruseri.begin(), siruseri.end(), myfunction);
    for (int i = 0; i < total_events; ++i)
    {
        if (blocked_till < siruseri[i].start)
        {
            ++max_events;
            blocked_till = siruseri[i].end;
        }
        else
        {
            continue;
        }
    }
    cout << max_events;
    return 0;


}
