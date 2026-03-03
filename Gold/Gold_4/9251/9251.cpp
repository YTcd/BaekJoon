#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string firstString;
    string secondString;
    cin >> firstString >> secondString;

    int firstSize = firstString.size();
    int secondSize = secondString.size();

    vector<vector<int>> dp(firstSize + 1, vector<int>(secondSize + 1, 0));

    for (int i = 1; i <= firstSize; i++)
    {
        for (int j = 1; j <= secondSize; j++)
        {
            char a = firstString[i - 1];
            char b = secondString[j - 1];
            if (a == b)
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[firstSize][secondSize];

    return 0;
}