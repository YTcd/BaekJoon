#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int level;
    cin >> level;

    vector<vector<int>> vec(level);
    for (int i = 0; i < level; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            int temp;
            cin >> temp;
            vec[i].push_back(temp);
        }
    }

    for (int i = level - 2; i >= 0; i--)
    {
        for (int j = 0; j < i + 1; j++)
        {
            vec[i][j] = vec[i][j] + max(vec[i + 1][j], vec[i + 1][j + 1]);
        }
    }

    cout << vec[0][0];

    return 0;
}