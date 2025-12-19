#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    bool checked;
    vector<int> links;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int nodeCount;
    cin >> nodeCount;

    int linkCount;
    cin >> linkCount;

    vector<Node> nodes(nodeCount, {false, vector<int>()});

    for (int i = 0; i < linkCount; i++)
    {
        int startPoint, endPoint;
        cin >> startPoint >> endPoint;
        nodes[startPoint-1].links.push_back(endPoint-1);
        nodes[endPoint-1].links.push_back(startPoint-1);
    }

    queue<Node> que;
    que.push(nodes[0]);
    nodes[0].checked = true;

    while (!que.empty())
    {
        Node node = que.front();
        que.pop();
        for (int i = 0; i < node.links.size(); i++)
        {
            if (nodes[node.links[i]].checked == false)
            {
                que.push(nodes[node.links[i]]);
                nodes[node.links[i]].checked = true;
            }
        }
    }

    int checkedCount = 0;
    for (int i = 0; i < nodeCount; i++)
    {
        if (nodes[i].checked == true)
        {
            checkedCount++;
        }
    }

    cout << checkedCount - 1;
    
    return 0;
}