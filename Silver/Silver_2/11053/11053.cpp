
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countOfNumber;
vector<int> vec;

void DP(vector<int> &dp, int index)
{
    if (index == countOfNumber)
    {
        return;
    }

    int MAX = 1;
    for (int i = 0; i < index; i++)
    {
        if (vec[i] < vec[index])
        {
            MAX = max(MAX, dp[i] + 1);
        }
    }

    dp[index] = MAX;

    DP(dp, index + 1);
    return;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> countOfNumber;
    if (countOfNumber == 1)
    {
        cout << 1;
        return 0;
    }
    for (int i = 0; i < countOfNumber; i++)
    {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }

    vector<int> dp(countOfNumber);

    dp[0] = 1;
    DP(dp, 0);
    cout << *max_element(dp.begin(), dp.end());

    return 0;
}