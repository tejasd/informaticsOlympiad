#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class vote_count
{
    public:
    int number, novotes;
};

bool compare (vote_count a, vote_count b)
{
    return a.novotes > b.novotes;
}

int main()
{
    vector <vote_count> votes;
    int total_candidates, total_votes, vote;
    cin >> total_candidates;
    votes.resize(total_candidates);
    cin >> total_votes;
    for (int i = 0; i < total_candidates;++i)
    {
        votes[i].novotes = 0;
        votes[i].number = i+1;
    }
    for (int i = 0; i < total_votes; ++i)
    {
        cin >> vote;
        ++votes[vote-1].novotes;

    }
    sort (votes.begin(), votes.end(), compare);
    cout << votes[2].number << endl;

    return 0;

}

