#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int row, col;
    cin >> row >> col;

    vector<vector<int>> vec(row, vector<int>());
    vector<vector<int>> result(row, vector<int>(col, -1));

    int startRow, startCol;
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int temp;
            cin >> temp;
            if (temp == 0)
            {
                result[i][j] = temp;
            }
            else if (temp == 2)
            {
                result[i][j] = 0;
                startRow = i;
                startCol = j;
            }
            vec[i].push_back(temp);
        }
    }

    queue<pair<int, int>> que;
    que.push({startRow, startCol});
    while(que.empty() != true)
    {
        pair<int, int> current = que.front();
        que.pop();
        int x = current.first;
        int y = current.second;
        
        if (x-1 >= 0 && result[x-1][y] == -1 && result[x-1][y] != 0)
        {
            result[x-1][y] = result[x][y] + 1;
            que.push({x-1, y});
        }
        if (x+1 < row && result[x+1][y] == -1 && result[x+1][y] != 0)
        {
            result[x+1][y] = result[x][y] + 1;
            que.push({x+1, y});
        }
        if (y-1 >= 0 && result[x][y-1] == -1 && result[x][y-1] != 0)
        {
            result[x][y-1] = result[x][y] + 1;
            que.push({x, y-1});
        }
        if (y+1 < col && result[x][y+1] == -1 && result[x][y+1] != 0)
        {
            result[x][y+1] = result[x][y] + 1;
            que.push({x, y+1});
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << result[i][j];
            if (j != col-1)
            {
                cout << ' ';
            }
            else
            {
                cout << '\n';
            }
        }
    }
    
    return 0;
}