#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    vector<int> links;
    bool visited = false;
    int parentIndex;
    int linkSize = -1;
};

void dfs(vector<Node> &nodes, int index)
{
    Node &thisNode = nodes[index];
    thisNode.visited = true;
    if (thisNode.linkSize == -1)
    {
        thisNode.linkSize = thisNode.links.size();
    }

    for (int i = 0; i < thisNode.linkSize; i++)
    {
        int nextIndex = thisNode.links[i];
        if (nodes[nextIndex].visited == false)
        {
            nodes[nextIndex].parentIndex = index;
            dfs(nodes, nextIndex);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int nodeCount;
    cin >> nodeCount;

    vector<Node> nodes(nodeCount);

    for (int i = 0; i < nodeCount - 1; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        nodes[temp1 - 1].links.push_back(temp2 - 1);
        nodes[temp2 - 1].links.push_back(temp1 - 1);
    }

    dfs(nodes, 0);

    for (int i = 1; i < nodeCount; i++)
    {
        cout << nodes[i].parentIndex + 1 << '\n';
    }

    return 0;
}