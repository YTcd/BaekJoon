#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> durations;
vector<vector<int>> prereq;
vector<int> memo;

int DFS(int destination)
{
    if (memo[destination] != -1)
    {
        return memo[destination];
    }

    int MAX = 0;
    for (int i = 0; i < prereq[destination].size(); i++)
    {
        MAX = max(DFS(prereq[destination][i]), MAX);
    }
    memo[destination] = MAX + durations[destination];
    return memo[destination];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int countOfTestCase;
    cin >> countOfTestCase;

    for (int i = 0; i < countOfTestCase; i++)
    {
        durations.clear();
        int countOfBuilding, countOfRules;
        cin >> countOfBuilding >> countOfRules;
        memo.assign(countOfBuilding, -1);
        prereq.assign(countOfBuilding, vector<int>());

        for (int j = 0; j < countOfBuilding; j++)
        {
            int duration;
            cin >> duration;
            durations.push_back(duration);
        }

        for (int j = 0; j < countOfRules; j++)
        {
            int ruleF, ruleB;
            cin >> ruleF >> ruleB;
            prereq[ruleB - 1].push_back(ruleF - 1);
        }

        int destination;
        cin >> destination;

        cout << DFS(destination - 1) << "\n";
    }

    return 0;
}