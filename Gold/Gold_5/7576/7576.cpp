#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct cell {
    int x;
    int y;
    int val;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int col, row;
    cin >> col >> row;

    vector<vector<int>> vec(row, vector<int>(col));

    queue<cell> cells;

    bool isAllDone = true;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int temp;
            cin >> temp;
            vec[i][j] = temp;
            if (temp == 0)
            {
                isAllDone = false;
            }
            else if (temp == 1)
            {
                cells.push({i, j, temp});
            }
        }
    }

    if (isAllDone)
    {
        cout << 0;
        return 0;
    }

    int count = 0;
    while(true)
    {
        int size = cells.size();
        for (int i = 0; i < size; i++)
        {
            cell temp = cells.front();
            cells.pop();
            int x = temp.x;
            int y = temp.y;
            int val = temp.val;

            if (x > -1 && x < row && y > -1 && y < col)
            {
                if (x+1 < row && vec[x+1][y] == 0)
                {
                    vec[x+1][y] = 1;
                    cells.push({x+1, y, 1});
                }

                if (x-1 > -1 && vec[x-1][y] == 0)
                {
                    vec[x-1][y] = 1;
                    cells.push({x-1, y, 1});
                }

                if (y+1 < col && vec[x][y+1] == 0)
                {
                    vec[x][y+1] = 1;
                    cells.push({x, y+1, 1});
                }

                if (y-1 > -1 && vec[x][y-1] == 0)
                {
                    vec[x][y-1] = 1;
                    cells.push({x, y-1, 1});
                }
            }
        }
        size = cells.size();
        if (size == 0)
        {
            break;
        }
        count++;
    }

    bool isDone = true;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (vec[i][j] == 0)
            {
                isDone = false;
            }
        }
    }

    if (isDone)
    {
        cout << count;
    }
    else
    {
        cout << -1;
    }

    return 0;
}