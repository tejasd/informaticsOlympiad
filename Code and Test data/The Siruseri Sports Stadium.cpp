#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
using namespace std;

int no_of_events, input1, input2, counter = 0, last_end_time = 0;

struct start_end_time
{
    int start,end;
}data [100001];

bool is_least (int i)
{
    int min = data[i].end;
    for (int j = i+1; j < no_of_events; ++j)
    {
        if (min < data[j].end)
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;

}


int compare (const void * a, const void * b)
{
    start_end_time entry1, entry2;
    entry1 = *(start_end_time*)a;
    entry2 = *(start_end_time*)b;
    if (entry1.start > entry2.start)
    {
        return 1;
    }
    else if (entry1.start == entry2.start)
    {
        if (entry1.end > entry2.end)
        {
            return 1;
        }
        else if (entry1.end == entry2.end)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return -1;
    }
}

/*bool comp (const start_end_time &a, const start_end_time &b)
{
    return a.start > b.start;

}*/



int main ()
{

    //input sequence
    cin >> no_of_events;
    for (int i = 0; i < no_of_events; ++i)
    {
        cin >> data[i].start >> data[i].end;
        data[i].end += data[i].start - 1;

    }
    //std::sort (data,&data[no_of_events-1], comp);
    qsort (data,no_of_events, sizeof(start_end_time), compare);

    /*/output sequence - debug
    for (int i = 0; i < no_of_events; ++i)
    {
        cout << data[i].start << " " << data[i].end << endl;
    }
    cout << "TO\n";*/


    for (int i = 0; i < no_of_events; ++i)
    {
        if (data[i].start > last_end_time)
        {
            if (is_least(i) == true)
            {
                ++counter;
                last_end_time = data[i].end;
            }
            else
            {
                //cout << "Not true for " << i << endl;
            }

        }
        else
        {

            continue;
        }
    }
    cout << counter << endl;
    return 0;

}
