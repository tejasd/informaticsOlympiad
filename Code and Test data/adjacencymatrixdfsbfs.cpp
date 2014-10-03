/*practice problem for adjacency matrix representation of graph*/

#define nvertices 15

#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <queue>

using namespace std;



bool visited [nvertices], processed [nvertices];

struct graph
{
    bool graph_paths [nvertices][nvertices];
    char vertices_data [nvertices];

}map_of_life;

void read_data_of_vertices ()
{
    for (int i = 0; i < nvertices; ++i)
    {
        cin >> map_of_life.vertices_data[i];


    }
    return;
}
void input_edges ()
{
    string input;
    int x,y;
    char a;
    for (int i = 0;i < 14;++i)
    {

            cin >> x >> y;
            map_of_life.graph_paths[x-1][y-1] = true;
            map_of_life.graph_paths[y-1][x-1] = true;

    }
    return;


}
void initialize_graph ()
{
    for (int i = 0; i < nvertices; ++i)
    {
        for (int j = 0; j < nvertices; ++j)
        {
            map_of_life.graph_paths[i][j] = false;
        }
    }
    return;
}
void process_vertex (int vertex)
{
    cout << map_of_life.vertices_data[vertex] << endl;
    return;
}

void bfs ()
{
    int current_verex;
    queue <int> brfs;
    brfs.push(0);
    for (;;)
    {
        if (brfs.empty())
        {
            break;
        }
        current_verex = brfs.front();
        brfs.pop();
        if (processed[current_verex] == false)
        {

            for (int j = 0; j < nvertices; ++j)//precessing the vertex
            {
                if (map_of_life.graph_paths[current_verex][j] == true)
                {
                        brfs.push(j);
                        //cout << "Pushed " << j<< endl;
                        visited [j] = true;


                }
            }
            process_vertex(current_verex);
            processed[current_verex] = true;

        }
        else
        {
            continue;
        }

    }
}



void dfs ()
{
    int current_verex;
    stack <int> drfs;
    drfs.push(0);
    for (;;)
    {
        if (drfs.empty())
        {
            break;
        }
        current_verex = drfs.top();
        drfs.pop();
        if (processed[current_verex] == false)
        {

            for (int j = 0; j < nvertices; ++j)//precessing the vertex
            {
                if (map_of_life.graph_paths[current_verex][j] == true)
                {
                    if (visited[j] == false)
                    {
                        drfs.push(j);
                        visited [j] = true;
                    }

                }
            }
            process_vertex(current_verex);
            processed[current_verex] = true;

        }
        else
        {
            continue;
        }

    }
}

void refresh_visited_processed ()
{
    for (int i = 0; i < nvertices; ++i)
    {
        visited[i] = false;
        processed[i] = false;
    }
    return;
}



int main()
{
    initialize_graph();
    read_data_of_vertices();
    input_edges();
    refresh_visited_processed();
    for (int i = 0; i< nvertices; ++i)
    {
        cout << map_of_life.vertices_data[i] << endl;
    }
    for (int i= 0; i < nvertices; ++i)
    {
        for (int j= 0; j < nvertices; ++j)
        {
            cout << map_of_life.graph_paths[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Beginning BFS --------\n";
    bfs();
    cout << "Beginning DFS --------\n";
    refresh_visited_processed();
    dfs();
    return 0;

}
