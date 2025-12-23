#include <iostream>
#include <vector>

using namespace std;

void dfs(int xPos, int yPos, int size, vector<vector<int>> &vec, int &whiteCount, int &blueCount);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int size;
    cin >> size;

    vector<vector<int>> vec(size);

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int num;
            cin >> num;
            vec[i].push_back(num);
        }
    }

    int whiteCount = 0;
    int blueCount = 0;
    dfs(0, 0, size, vec, whiteCount, blueCount);
    cout << whiteCount << '\n'
         << blueCount << '\n';

    return 0;
}

void dfs(int xPos, int yPos, int size, vector<vector<int>> &vec, int &whiteCount, int &blueCount)
{
    int defaultVal = vec[xPos][yPos];
    bool isAllSame = true;
    int xSize = size + xPos;
    int ySize = size + yPos;
    for (int i = xPos; i < xSize; i++)
    {
        for (int j = yPos; j < ySize; j++)
        {
            if (vec[i][j] != defaultVal)
            {
                isAllSame = false;
                break;
            }
        }
    }

    if (!isAllSame)
    {
        dfs(xPos, yPos, size / 2, vec, whiteCount, blueCount);
        dfs(xPos, yPos + size / 2, size / 2, vec, whiteCount, blueCount);
        dfs(xPos + size / 2, yPos, size / 2, vec, whiteCount, blueCount);
        dfs(xPos + size / 2, yPos + size / 2, size / 2, vec, whiteCount, blueCount);
    }
    else
    {
        defaultVal == 1 ? blueCount++ : whiteCount++;
        return;
    }
}