#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tableSize, testCount;

    cin >> tableSize >> testCount;

    vector<vector<int>> vec(tableSize, vector<int>(tableSize));

    for (int i = 0; i < tableSize; i++)
    {
        int sum = 0;
        for (int j = 0; j < tableSize; j++)
        {
            int temp;
            cin >> temp;
            sum += temp;
            vec[i][j] = sum;
        }
    }

    vector<int> result(testCount);

    for (int i = 0; i < testCount; i++)
    {
        int testX1, testY1, testX2, testY2;
        cin >> testX1 >> testY1 >> testX2 >> testY2;

        int sum = 0;
        for (int j = testX1; j <= testX2; j++)
        {
            if (testY1 == 1)
            {
                sum += vec[j - 1][testY2 - 1];
            }
            else
            {
                sum += vec[j - 1][testY2 - 1] - vec[j - 1][testY1 - 2];
            }
        }
        result[i] = sum;
    }

    for (int i = 0; i < testCount; i++)
    {
        cout << result[i] << '\n';
    }

    return 0;
}