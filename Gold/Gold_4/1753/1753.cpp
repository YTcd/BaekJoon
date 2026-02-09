#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

struct vertexInfo {
    vector<pair<int,int>> links;
};

struct cmp
{
    bool operator()(pair<int,int> &a, pair<int,int> &b)
    {
        return a.second > b.second;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int vertexCnt, edgeCnt;
    cin >> vertexCnt >> edgeCnt;

    int startPoint;
    cin >> startPoint;

    vector<vertexInfo> vertexes(vertexCnt + 1);
    for (int i = 0; i < edgeCnt; i++)
    {
        int start, end, weight;
        cin >> start >> end >> weight;
        vertexes[start].links.push_back({end,weight});
    }

    vector<int> dijkstra(vertexCnt + 1, INT_MAX);

    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

    dijkstra[startPoint] = 0;
    pq.push({startPoint, 0});

    while (pq.empty() == false)
    {
        pair<int, int> nodeInfo = pq.top();
        pq.pop();
        if (nodeInfo.second > dijkstra[nodeInfo.first])
        {
            continue;
        }
        int size = vertexes[nodeInfo.first].links.size();
        for (int i = 0; i < size; i++)
        {
            int checkIndex = vertexes[nodeInfo.first].links[i].first;
            int checkWeight = vertexes[nodeInfo.first].links[i].second;
            if (dijkstra[checkIndex] > checkWeight + nodeInfo.second)
            {
                dijkstra[checkIndex] = checkWeight + nodeInfo.second;
                pq.push({checkIndex, dijkstra[checkIndex]});
            }
        }
    }


    for (int i = 1; i <= vertexCnt; i++)
    {
        if (dijkstra[i] != INT_MAX)
        {
            cout << dijkstra[i] << '\n';
        }
        else
        {
            cout << "INF\n";
        }
        
    }

    return 0;
}