#include <iostream>
#include <stack>
using namespace std;

stack <int> below_threshold;

bool hate_relations[3000][3000], done_pass_and_not_found = false;
int degree_of_graph [3000],final_answer;

int main ()
{
    int no_of_nobles,no_of_pairs,k,from,to;
    cin >> no_of_nobles >> no_of_pairs >> k;
    final_answer = no_of_nobles;
    for (int i = 0; i < no_of_nobles; ++i)
    {
        for (int j = 0; j < no_of_nobles; ++j)
        {
            hate_relations[i][j] = false;
        }
    }
    for (int i = 0; i < no_of_nobles; ++i)
    {
        degree_of_graph[i] = 0;
    }
    for (int i = 0; i < no_of_pairs; ++i)
    {
        cin >> from >> to;
        --from;
        --to;
        hate_relations[from][to] = true;
        hate_relations[to][from] = true;
        ++degree_of_graph[from];
        ++degree_of_graph[to];
    }
    //actual calculations

    for (;;)
    {
        if (done_pass_and_not_found)
        {
            if (final_answer > 0)
            {
                cout << "YES\n";
                cout << final_answer << endl;
                return 0;
            }
            else
            {
                cout << "NO\n";
                return 0;
            }

        }
        else if (below_threshold.empty())
        {
            for (int i = 0; i < no_of_nobles; ++i)
            {
                if (degree_of_graph[i] < k && degree_of_graph[i] != -1)
                {
                    below_threshold.push(i);
                }
            }
            if (below_threshold.empty())
            {
                done_pass_and_not_found = true;
            }
        }
        else
        {
            degree_of_graph[below_threshold.top()] = -1;

            for (int i = 0; i < no_of_nobles; ++i)
            {
                if (hate_relations[below_threshold.top()][i])
                {
                    hate_relations[below_threshold.top()][i] = false;
                    hate_relations[i][below_threshold.top()] = false;
                    --degree_of_graph[i];


                }
            }
            below_threshold.pop();
            --final_answer;
        }
    }
    cout << final_answer << endl;
    return 0;



}
