#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<string> vec;

bool BellmanFord(int startPos, int nodeCnt, vector<vector<pair<int,int>>> &nodes)
{
    vector<int> distance(nodeCnt, INT_MAX);
    distance[startPos] = 0;

    for (int i = 0; i < nodeCnt; i++)
    {
        int linkSize = nodes[i].size();
        for (int j = 0; j < linkSize; j++)
        {
            int endPos = nodes[i][j].first;
            int cost = nodes[i][j].second;
            if (distance[i] != INT_MAX && distance[i] + cost < distance[endPos])
            {
                distance[endPos] = distance[i] + cost;    
            }
        }
    }

    distance;
}

void solveTestCase()
{
    int nodeCnt, lineCnt, holeCnt;
    cin >> nodeCnt >> lineCnt >> holeCnt;

    vector<vector<pair<int,int>>> nodes(nodeCnt);

    for (int i = 0; i < lineCnt + holeCnt; i++)
    {
        int startPos, endPos, cost;
        cin >> startPos >> endPos >> cost;

        if (i < lineCnt)
        {
            nodes[startPos-1].push_back({endPos-1, cost});
        }
        else
        {
            nodes[startPos-1].push_back({endPos-1, -cost});
        }

        // nodes[시작점 - 1] == {(끝점 - 1), 코스트}
    }
    

    for (int i = 0; i < nodeCnt; i++)
    {
        bool result = BellmanFord(i, nodeCnt, nodes);
        vec.push_back(result ? "YES" : "NO");        
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    short testCaseCnt;
    cin >> testCaseCnt;

    while (testCaseCnt--)
    {
        solveTestCase();
    }

    for (int i = 0; i < testCaseCnt; i++)
    {
        cout << vec[i] << "\n";
    }

    return 0;
}