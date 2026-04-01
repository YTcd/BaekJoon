#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int answer = 0;
pair<int, int> MAX_NODE = {0, 0};
vector<bool> visited;

void DFS(int index, int weight, vector<vector<pair<int, int>>>& nodes)
{
    int size = nodes[index].size();
    if (weight > MAX_NODE.second)
    {
        MAX_NODE.first = index;
        MAX_NODE.second = weight;
        answer = weight;
    }

    for (int i = 0; i < size; i++)
    {
        int nextIndex = nodes[index][i].first - 1;
        int nextWeight = nodes[index][i].second;
        if (visited[nextIndex])
        {
            continue;
        }
        visited[nextIndex] = true;
        DFS(nextIndex, weight + nextWeight, nodes);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int nodeCnt;
    cin >> nodeCnt;

    vector<vector<pair<int, int>>> nodes(nodeCnt);

    for (int i = 0; i < nodeCnt; i++)
    {
        int nodeNumber;
        cin >> nodeNumber;
        while (true)
        {
            int edgeTarget;
            cin >> edgeTarget;
            if (edgeTarget == -1)
            {
                break;
            }
            int edgeWeight;
            cin >> edgeWeight;
            nodes[nodeNumber - 1].push_back({edgeTarget, edgeWeight});
        }
    }

    visited.resize(nodeCnt);
    visited.assign(nodeCnt, false);
    visited[0] = true;
    DFS(0, 0, nodes);
    visited.assign(nodeCnt, false);
    visited[MAX_NODE.first] = true;
    DFS(MAX_NODE.first, 0, nodes);
    cout << answer;

    return 0;
}