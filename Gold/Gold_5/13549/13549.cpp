#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    
    vector<int> memo(100001, 100000);
    queue<int> que;

    memo[N] = 0;
    int num;
    que.push(N);
    while(que.empty() == false)
    {
        num = que.front();
        que.pop();

        if (num == K)
        {
            break;
        }

        if (num * 2 < 100001 && memo[num * 2] > memo[num])
        {
            memo[num * 2] = memo[num];
            que.push(num * 2);
        }

        if (num + 1 < 100001 && memo[num + 1] > memo[num])
        {
            memo[num + 1] = memo[num] + 1;
            que.push(num + 1);
        }

        if (num - 1 < 100001 && memo[num - 1] > memo[num])
        {
            memo[num - 1] = memo[num] + 1;
            que.push(num - 1);
        }
    }

    cout << memo[K];

    return 0;
}