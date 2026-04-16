#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int cnt;
    cin >> cnt;

    vector<pair<long long, long long>> arr(cnt);
    for (int i = 0; i < cnt; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    long long sum = 0;
    for (int i = 0; i < cnt; i++)
    {
        int j = (i + 1) % cnt;
        sum += (arr[i].first * arr[j].second) - (arr[i].second * arr[j].first);
    }

    long long result = abs(sum) / 2;
    // 소수점이하 1자리까지 출력
    if (sum % 2 == 0)
    {
        cout << result << ".0" << endl;
    }
    else
    {
        cout << result << ".5" << endl;
    }

    return 0;
}
