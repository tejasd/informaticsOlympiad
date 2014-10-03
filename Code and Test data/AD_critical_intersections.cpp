// This is the O(m+n) complexity solution

#include <iostream>
#include <stack>
using namespace std;

bool processed [300];

bool is_articulation_point [300];

bool discovered [300];

int edges [300][300];
int tree_edges [300][300];
int back_edges [300][300];
int no_of_edges [300];
int no_of_back_edges [300];
int no_of_tree_edges [300];
int entry [300];
int exit [300];
int time_entry_exit = 1;
int total_articulation_points;

bool is_ancestor (int this_, int of)
{
    if (entry[this_] < entry [of] && exit [this_] > exit [of])
    {
        return true;
    }
    else
    {
        return false;
    }
}

void dfs (int start)
{
    int next_vertices;
    entry [start] = time_entry_exit;
    ++time_entry_exit;
    for (int i = 0; i < no_of_edges[start]-1; ++i)
    {
        if (discovered[edges[start][i]])
        {
            back_edges[start][no_of_back_edges[start]] = edges[start][i];
            ++no_of_back_edges[start];
            back_edges[edges[start][i]][no_of_back_edges[i]] = start;
            ++no_of_back_edges[edges[start][i]];

        }
        else
        {
            discovered [edges[start][i]] = true;
            tree_edges[start][no_of_tree_edges[start]] = edges[start][i];
            ++no_of_tree_edges[start];
            /*tree_edges[edges[start][i]][no_of_tree_edges[edges[start][i]]] = start;
            ++no_of_tree_edges[edges[start][i]];*/
            cout << "Visited " << edges[start][i] << endl;

            dfs (edges[start][i]);
        }

    }
    processed [start] = true;
    exit[start] = time_entry_exit;
    ++time_entry_exit;
    return;

}

int main ()
{
    int no_of_vertices, total_edges, x,y;
    cin >> no_of_vertices >> total_edges;
    total_articulation_points = no_of_vertices;
    for (int i = 0; i < no_of_vertices; ++i) //initialising graph
    {
        processed [i] = discovered[i] = false;
        edges[i][0] = i;
        tree_edges[i][0] = back_edges[i][0] = i;
        no_of_back_edges[i] = 1;
        no_of_edges[i] = 1;
        no_of_tree_edges[i] = 1;
        is_articulation_point [i] = true;

    }
    for (int i = 0; i < total_edges; ++i)
    {
        cin >> x >> y;
        --x;
        --y;
        edges[x][no_of_edges[x]] = y;
        ++no_of_edges[x];
        edges[y][no_of_edges[y]] = x;
        ++no_of_edges[y];
    }
    dfs (0);


    //checking for articulation points
    for (int i = 0; i < no_of_vertices; ++i)
    {
        if (no_of_tree_edges[i] == 1)
        {
            is_articulation_point [i] = false;
            --total_articulation_points;
        }

    }
    for (int i = 0; i < no_of_vertices; ++i)
    {
        if (no_of_back_edges[i] > 1)
        {
            for (int j = 1, next = i; j < no_of_back_edges[i]; ++j,next = i )
            {
                if (is_ancestor(i,back_edges[i][j]))
                {
                    bool flag = true;
                    int temp_next = next;
                    if (no_of_back_edges[next] == 2)
                    {
                        next = tree_edges[next][1];
                    }
                    else
                    {
                        for (int i = 1; i < no_of_tree_edges[next]; ++i)
                        {
                            if (is_ancestor(tree_edges[next][i],back_edges[i][j]))
                            {
                                next = tree_edges[next][i];
                                break;
                            }
                        }
                    }
                    for (;;)
                    {
                        flag = true;
                        temp_next = next;
                        for (int k = 1; k < no_of_tree_edges[next]; ++k)
                        {
                            if (is_ancestor(tree_edges[next][k],back_edges[i][j]))
                            {
                                temp_next = tree_edges[next][k];
                                if (flag)
                                {
                                    is_articulation_point[next] = false;
                                    --total_articulation_points;
                                }

                            }
                            else
                            {
                                flag = false;
                                if (is_articulation_point[next] == false)
                                {
                                    is_articulation_point[next] = true;
                                    ++total_articulation_points;
                                }


                            }
                        }
                        if (temp_next == next)
                        {
                            break;
                        }
                        else
                        {
                            next = temp_next;
                        }
                    }
                }
            }
        }
    }
    if (no_of_tree_edges[0] > 1)
    {

        is_articulation_point[0] = true;
    }
    else
    {
        is_articulation_point[0] = false;
    }
    cout << total_articulation_points << endl;
    for (int i = 0; i < no_of_vertices; ++i)
    {
        if (is_articulation_point[i])
        {
            cout << i+1 <<endl;
        }
    }
    cout << "debug " << no_of_back_edges[1] << " " << no_of_tree_edges[1] << " " << no_of_edges[1] << endl;
    return 0;







}

