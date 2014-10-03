//assuming max ministers are 2000
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class paths
{
    public:
    int incoming, outgoing;
    paths ()
    {
        incoming = -1;
        outgoing = -1;
    }
};

class adjacency_matrix
{
    public:
    int road[2000];
    int counter;
};

bool roads [2000][2000];
int no_of_ministers, max_outgoing, max_num = 0, first, last;
vector <paths> ministers_list;
vector <adjacency_matrix> ministers_list_2;
stack <int> remaining_nodes;

int main ()
{
    //input sequence
    cin >> no_of_ministers;
    ministers_list_2.resize(no_of_ministers);
    for (int i = 0; i < no_of_ministers; ++i) //initialize bool adj matrix
    {
        for (int j = 0; j < no_of_ministers; ++j)
        {
            roads[i][j] = false;
        }
    }
    for (int i = 0; i < no_of_ministers; ++i)
    {
        cin >> ministers_list_2[i].counter;
        if (ministers_list_2[i].counter > max_num)
        {
            max_outgoing = i;
            max_num = ministers_list_2[i].counter;
        }
        for (int j = 0; j < ministers_list_2[i].counter; ++j)
        {
            cin >> ministers_list_2[i].road[j];
            roads[i][(ministers_list_2[i].road[j])-1] = true;
            //cout << "i = " << i << " j = " << j << endl;
        }
    }

    //input sequence done

    //setting up basic path
    ministers_list.resize(no_of_ministers);
    ministers_list[0].incoming = 0;
    ministers_list[0].outgoing = ministers_list_2[0].road[0];
    ministers_list[ministers_list_2[0].road[0]-1].incoming = 1;
    ministers_list[ministers_list_2[0].road[0]-1].outgoing = 0;

    //initial path building

    /*for (int i = ministers_list_2[0].road[0];;)
    {
        bool brk = true;
        for (int j = 0; j < ministers_list_2[i-1].counter; ++j)
        {
            if (j == ministers_list_2[i].counter - 1)
            {
                if (ministers_list[j-1].incoming == -1)
                {
                    ministers_list[j-1].incoming = i;
                    ministers_list[j-1].outgoing = 0;
                    ministers_list[i-1].outgoing = i;
                    i = j;
                    break;
                }
                else
                {
                    last = i-1;
                    first = max_outgoing;
                    brk = false;
                    break;
                }

            }
            else
            {
                if (ministers_list[j-1].incoming == -1)
                {
                    ministers_list[j-1].incoming = i;
                    ministers_list[j-1].outgoing = 0;
                    ministers_list[i-1].outgoing = i;
                    i = j;
                    break;
                }
            }
        }
        if (brk == false)
        {
            break;
        }
    }*/
    //initial path building done



    for (int i = 0; i < no_of_ministers; ++i) //building stack for remaining nodes
    {
        if (ministers_list[i].incoming == -1)
        {
            remaining_nodes.push(i);
        }
    }//the stack contains array indices and not node name (i.e node name -1)

    for (int i = 0; remaining_nodes.empty () != true;)
    {
        i = remaining_nodes.top();
        remaining_nodes.pop();
        //check if i can be first in list
        if (roads[i][first])
        {
            ministers_list[i].incoming = 0;
            ministers_list[i].outgoing = first+1;
            ministers_list[first].incoming = i+1;
            first = i;
        }
        else if (roads[last][i])
        {
            ministers_list[i].incoming = last+1;
            ministers_list[i].outgoing = 0;
            ministers_list[last].outgoing = i+1;
            last = i;
        }
        else
        {
            int j = first;
            for (bool brk1 = true; brk1 != false;)
            {
                if (roads[j][i] && roads[i][ministers_list[j].outgoing-1])
                {
                    ministers_list[ministers_list[j].outgoing-1].incoming = i+1;
                    ministers_list[i].outgoing = ministers_list[j].outgoing;
                    ministers_list[j].outgoing = i+1;
                    ministers_list[i].incoming = j+1;

                }
                else
                {
                    if (ministers_list[j].outgoing == 0)
                    {
                        brk1 = false;
                    }
                    else
                    {
                        j = (ministers_list[j].outgoing)-1;
                    }
                }
            }
        }


    }
    //output sequence

    cout << "YES\n";



    cout << first+1 << " ";

    for (int i = first;;)
    {
        if (i == last)
        {
            cout << ministers_list[i].outgoing << " ";
            i = ministers_list[i].outgoing-1;
            break;
        }
        cout << ministers_list[i].outgoing << " ";
        i = ministers_list[i].outgoing-1;

    }
    cout << endl;
    return 0;



}

