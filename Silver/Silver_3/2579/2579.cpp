#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int stairCount;
    cin >> stairCount;
    
    vector<int> stairs;
    
    for (int i = 0; i < stairCount; i++)
    {
        int stairNum;
        cin >> stairNum;
        stairs.push_back(stairNum);
    }

    vector<int> dp(stairCount + 1);
    dp[1] = stairs[0];
    dp[2] = stairs[0] + stairs[1];
    
    for (int i = 3; i <= stairCount; i++)
    {
        dp[i] = max(dp[i - 2], dp[i - 3] + stairs[i - 2]) + stairs[i - 1];
    }
    
    cout << dp[stairCount];
    

    return 0;
}