#define MAXV  2000
#define MAXINT 100

#include <iostream>
using namespace std;


int adjacency_matrix [MAXV][MAXV];
bool directed;
char input;
int nedges;
int from,to,weight;
int A,B,greatest = 0;
int main ()
{



    cout << "Number of edges : ";
    cin >> nedges >> A >> B;

    for (int i = 0; i < MAXV; ++i)
    {
        for (int j = 0; j < MAXV; ++j)
        {
            adjacency_matrix[i][j] = MAXINT;
        }
    }

    cout << "Now enter the distance in format from to distance \n";
    for (int i = 0; i < nedges; ++i)
    {
        cin >> from >> weight >> to;
        --from;
        --to;
        adjacency_matrix[from][to] = weight;

        adjacency_matrix[to][from] = weight;
        if (to > greatest)
        {
            greatest = to;
            //cout << greatest << " here to\n";
        }
        else if (from > greatest )
        {
            greatest = from;
            //cout << greatest << " hear from\n";
        }


    }
    //actual calculation
    for (int k = 0; k <= greatest; ++k)
    {
        for (int i = 0; i <= greatest; ++i)
        {
            for (int j = 0; j <= greatest; ++j)
            {
                if (adjacency_matrix[i][k] + adjacency_matrix[k][j] < adjacency_matrix[i][j])
                {
                    adjacency_matrix[i][j] = adjacency_matrix[i][k] + adjacency_matrix[k][j];

                }
            }

        }
    }
    /*cout << "  ";
    for (int i = 1; i <= greatest; ++i)
    {
        cout << i << " ";
    }
    cout << endl;

    for (int i = 0; i < greatest; ++i)
    {
        cout << i+1 << " ";
        for (int j = 0; j < greatest; ++j)
        {
            cout << adjacency_matrix[i][j] << " ";
        }
        cout << endl;
    }*/

    if (adjacency_matrix[A-1][B-1] == MAXINT)
    {
        cout << "NO\n";
        //cout << adjacency_matrix[A-1][B-1] << endl;
    }

    else
    {
        cout << "YES\n";
        cout << adjacency_matrix[A-1][B-1] << endl;
    }
   // cout << greatest;
    return 0;


}
