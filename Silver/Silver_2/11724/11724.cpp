#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
    bool checked;
    vector<int> links;
};

void DFS(vector<node> &nodes, int start)
{
    if (nodes[start].checked == true)
    {
        return;
    }
    nodes[start].checked = true;

    for (int i = 0; i < nodes[start].links.size(); i++)
    {
        DFS(nodes, nodes[start].links[i]);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int nodeCount, linkCount;
    cin >> nodeCount >> linkCount;

    vector<node> nodes(nodeCount, {false, vector<int>()});

    for (int i = 0; i < linkCount; i++)
    {
        int a, b;
        cin >> a >> b;
        nodes[a - 1].links.push_back(b - 1);
        nodes[b - 1].links.push_back(a - 1);
    }

    int count = 0;

    for (int i = 0; i < nodeCount; i++)
    {
        if (nodes[i].checked == false)
        {
            DFS(nodes, i);
            count++;
        }
    }

    cout << count;

    return 0;
}