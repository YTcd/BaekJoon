#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct node
{
    bool checked;
    vector<int> links;
};

void DFS(vector<node>& nodes, int start, vector<int>& result);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int nodeCount, linkCount, startPoint;
    cin >> nodeCount >> linkCount >> startPoint;
    
    vector<node> nodes(nodeCount, {false, vector<int>()});
    for (int i = 0; i < linkCount; i++)
    {
        int a, b;
        cin >> a >> b;
        nodes[a-1].links.push_back(b-1);
        nodes[b-1].links.push_back(a-1);
    }

    for (int i = 0; i < nodeCount; i++)
    {
        sort(nodes[i].links.begin(), nodes[i].links.end());
    }

    vector<int> dfsResult;
    DFS(nodes, startPoint-1, dfsResult);
    for (int i = 0; i < dfsResult.size(); i++)
    {
        cout << dfsResult[i];
        if (i == dfsResult.size()-1)
        {
            cout << '\n';
        }
        else
        {
            cout << ' ';
        }
    }

    for (int i = 0; i < nodeCount; i++)
    {
        nodes[i].checked = false;
    }


    vector<int> bfsResult;
    queue<int> que;
    que.push(startPoint-1);
    nodes[startPoint-1].checked = true;

    while(que.empty() != true)
    {
        int current = que.front();
        que.pop();
        bfsResult.push_back(current+1);

        for (int i = 0; i < nodes[current].links.size(); i++)
        {
            if (nodes[nodes[current].links[i]].checked == false)
            {
                nodes[nodes[current].links[i]].checked = true;
                que.push(nodes[current].links[i]);
            }
        }
    }

    for (int i = 0; i < bfsResult.size(); i++)
    {
        cout << bfsResult[i];
        if (i != bfsResult.size()-1)
        {
            cout << ' ';
        }
    }
    return 0;
}

void DFS(vector<node>& nodes, int start, vector<int>& result)
{
    if (nodes[start].checked == true)
    {
        return;
    }
    nodes[start].checked = true;
    result.push_back(start+1);

    for (int i = 0; i < nodes[start].links.size(); i++)
    {
        DFS(nodes, nodes[start].links[i], result);
    }
}