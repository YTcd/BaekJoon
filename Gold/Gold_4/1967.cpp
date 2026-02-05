#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct nodeInfo{
    vector<int> target;
    vector<int> weight;
};

void DFS(int index, vector<int>& vec, vector<nodeInfo> &nodeInfo) {
    int size = nodeInfo[index].target.size();
    for (int i = 0; i < size; i++)
    {
        int targetIndex = nodeInfo[index].target[i];
        int weight = nodeInfo[index].weight[i];

        if (weight + vec[index] < vec[targetIndex])
        {
            vec[targetIndex] = weight + vec[index];
            DFS(targetIndex, vec, nodeInfo);
        }
    }

};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int nodeCnt, edgeCnt;
    cin >> nodeCnt >> edgeCnt;

    int startIndex;
    cin >> startIndex;

    vector<int> vec(nodeCnt+1, 11);

    vec[startIndex] = 0;

    vector<nodeInfo> nodeInfo(nodeCnt+1, {vector<int>(), vector<int>()});
    for (int i = 0; i < edgeCnt; i++)
    {
        int start, target, weight;
        cin >> start >> target >> weight;
        nodeInfo[start].target.push_back(target);
        nodeInfo[start].weight.push_back(weight);
    }

    DFS(startIndex, vec, nodeInfo);

    for (int i = 1; i <= nodeCnt; i++)
    {
        int cnt = vec[i];
        if (cnt == 11)
        {
            cout << "INF" << '\n';
        }
        else
        {
            cout << cnt << '\n';
        }
    }

    return 0;
}