#define MAXV 100
#define MAXDEGREE 50

#include <iostream>
#include <vector>

struct graph//creating a struct of graph - adjacency lists in matrices
{
    int edges [MAXV+1][MAXDEGREE];
    int degree [MAXV+1];
    int no_of_vertices;
    int no_of_edges;
}


void read_graph (graph *g, bool directed)
{
    int m, x, y; //m = no_of_edges, x,y = vertices pair
    initialize_graph (g);
    cin >> *g.no_of_vertices >> m;
    *g.no_of_edges = m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        insert_edge (g, x, y, directed);
    }
}

void initialize_edge (graph * g)
{
    *g.no_of_vertices  = 0;
    *g.no_of_edges = 0;
    for (int j = 0; j < MAXV; j++)
    {
        *g.degree[j] = 0;
    }
}

void insert_edge (graph *g, int x, int y, bool directed)
{
    if (*g.degree[x] > MAXDEGREE)
    {
        cout << "Warning : insertion (" << x << "," << y << ") exceeds max degree\n";
    }
    *g.edges[x][*g.degree[x]] = y;
    ++*g.degree[x];
    if (directed == false)
    {
        insert_edge(g, y, x, true );
    }
    else
    {
        *g.no_of_edges ++;
    }
}

void print_graph (graph *g)
{
    for (int i = 0; i < *g.no_of_vertices; ++i)
    {
        cout << i << " : ";
        for  (int j = 0; j < *g.no_of_edges[i]; ++j)
        {
            cout << " " << *g.edges[i][j];
        }
        cout << endl;
    }
}
        }
    }
}
    }
    }
    }
}

int main ()
{
    graph road_network;
    cout << "Please input the graph details :  ";
    read_graph (&road_network, false);
    print_graph(&road_network);
    return 0;
}
}
