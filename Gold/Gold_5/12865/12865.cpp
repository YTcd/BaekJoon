#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct wv
{
    int weight;
    int value;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K; // N : 갯수, K : 최대 무게
    cin >> N >> K;

    vector<wv> vec;

    for (int i = 0; i < N; i++)
    {
        int W, V; // W : 각 무게, V : 가치;
        cin >> W >> V;
        vec.push_back({W, V});
    }

    vector<int> dp(K + 1, 0);

    for (int i = 0; i < N; i++)
    {
        for (int j = K; j >= 0; j--)
        {
            if (j - vec[i].weight >= 0)
            {
                dp[j] = max(dp[j], dp[j - vec[i].weight] + vec[i].value);
            }
        }
    }

    cout << dp[K];

    return 0;
}