#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<string> vec;

bool BellmanFord(int nodeCnt, vector<tuple<int,int,int>> &edges)
{
    vector<int> dist(nodeCnt, 0); // just for minus circular check

    for (int i = 0; i < nodeCnt - 1; i++)
    {
        for (auto [u, v, cost] : edges)
        {
            if (dist[u] + cost < dist[v])
            {
                dist[v] = dist[u] + cost;
            }
        }
    }

    // check minus circular
    for (auto [u, v, cost] : edges)
    {
        if (dist[u] + cost < dist[v])
        {
            return true;
        }
    }

    return false;
}

void solveTestCase()
{
    int nodeCnt, lineCnt, holeCnt;
    cin >> nodeCnt >> lineCnt >> holeCnt;

    vector<tuple<int,int,int>> edges;

    // edges
    for (int i = 0; i < lineCnt; i++)
    {
        int startPos, endPos, cost;
        cin >> startPos >> endPos >> cost;

        edges.push_back({startPos - 1, endPos - 1, cost});
        edges.push_back({endPos - 1, startPos - 1, cost});
    }

    // wormholes
    for (int i = 0; i < holeCnt; i++)
    {
        int startPos, endPos, cost;
        cin >> startPos >> endPos >> cost;

        edges.push_back({startPos - 1, endPos - 1, -cost});
    }

    bool result = BellmanFord(nodeCnt, edges);
    vec.push_back(result ? "YES" : "NO");
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCaseCnt;
    cin >> testCaseCnt;

    int originalCnt = testCaseCnt;

    while (testCaseCnt--)
    {
        solveTestCase();
    }

    for (int i = 0; i < originalCnt; i++)
    {
        cout << vec[i] << "\n";
    }

    return 0;
}