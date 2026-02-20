#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int ans = 0;

struct NodeInfo
{
    vector<pair<int, int>> childs;
};

int DFS(int index, vector<NodeInfo>& nodes)
{
    int size = nodes[index].childs.size();
    if (size == 0)
    {
        return 0;
    }

    int MAX1 = 0;
    int MAX2 = 0;
    for (int i = 0; i < size; i++)
    {
        int nextIndex = nodes[index].childs[i].first;
        int nextNodeWeight = nodes[index].childs[i].second;

        int calcNum = DFS(nextIndex, nodes) + nextNodeWeight;
        if (calcNum >= MAX1)
        {
            MAX2 = MAX1;
            MAX1 = calcNum;
        }
        else if (calcNum > MAX2)
        {
            MAX2 = calcNum;
        }
    }

    ans = max(ans, MAX1 + MAX2);

    return MAX1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int nodeCnt;
    cin >> nodeCnt;

    vector<NodeInfo> nodes(nodeCnt + 1);
    int parentIndex, childIndex, weight;
    while (cin >> parentIndex >> childIndex >> weight)
    {
        nodes[parentIndex].childs.push_back({childIndex, weight});
    }

    DFS(1, nodes);
    cout << ans;

    return 0;
}