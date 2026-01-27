#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> result;

    int testCaseCnt;
    cin >> testCaseCnt;
    for (int i = 0; i < testCaseCnt; i++)
    {
        int stickerCount;
        cin >> stickerCount;
        vector<vector<int>> vec(2, vector<int>(stickerCount, 0));

        for (int j = 0; j < stickerCount; j++)
        {
            int temp;
            cin >> temp;
            vec[0][j] = temp;
        }
        for (int j = 0; j < stickerCount; j++)
        {
            int temp;
            cin >> temp;
            vec[1][j] = temp;
        }

        if (stickerCount == 1)
        {
            result.push_back(max(vec[0][0], vec[1][0]));
            continue;
        }
        else if (stickerCount == 2)
        {
            result.push_back(max(vec[0][0] + vec[1][1], vec[1][0] + vec[0][1]));
            continue;
        }

        vector<vector<int>> sums(2, vector<int>(stickerCount, 0));

        sums[0][0] = vec[0][0];
        sums[1][0] = vec[1][0];
        sums[0][1] = vec[1][0] + vec[0][1];
        sums[1][1] = vec[0][0] + vec[1][1];
        for (int j = 2; j < stickerCount; j++)
        {
            int upNum = vec[0][j];
            int downNum = vec[1][j];

            sums[0][j] = max(sums[1][j - 1], sums[1][j - 2]) + upNum;
            sums[1][j] = max(sums[0][j - 1], sums[0][j - 2]) + downNum;
        }

        int mx1 = *max_element(sums[0].begin(), sums[0].end());
        int mx2 = *max_element(sums[1].begin(), sums[1].end());
        result.push_back(max(mx1, mx2));
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
        if (i < result.size() - 1)
        {
            cout << '\n';
        }
    }

    return 0;
}