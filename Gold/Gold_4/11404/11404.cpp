#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cityCount, busCount;
    cin >> cityCount >> busCount;

    vector<vector<int>> graph(cityCount + 1, vector<int>(cityCount + 1, INT_MAX));

    for (int i = 0; i < busCount; i++)
    {
        int start, end, cost;
        cin >> start >> end >> cost;
        graph[start][end] = min(graph[start][end], cost);
    }

    for (int i = 0; i < cityCount + 1; i++)
    {
        graph[i][i] = 0;
    }

    for (int m = 1; m < cityCount + 1; m++)
    {
        for (int s = 1; s < cityCount + 1; s++)
        {
            for (int e = 1; e < cityCount + 1; e++)
            {
                if (graph[s][m] != INT_MAX && graph[m][e] != INT_MAX &&
                    graph[s][e] > graph[s][m] + graph[m][e])
                {
                    graph[s][e] = graph[s][m] + graph[m][e];
                }
            }
        }
    }

    for (int i = 1; i < cityCount + 1; i++)
    {
        for (int j = 1; j < cityCount + 1; j++)
        {
            if (graph[i][j] == INT_MAX)
            {
                cout << "0";
            }
            else
            {
                cout << graph[i][j];
            }

            if (j != cityCount)
            {
                cout << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}