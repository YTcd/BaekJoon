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

    vector<cell> cells;

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
                cells.push_back({i, j, 1});
            }
        }
    }

    if (isAllDone)
    {
        cout << 0;
        return 0;
    }

    

    return 0;
}