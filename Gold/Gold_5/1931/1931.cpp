#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> times;

    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        times.push_back({start, end});
    }

    sort(times.begin(), times.end(), [](auto &a, auto &b)
         {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second; });

    int count = 0;
    int lastEnd = 0;

    for (int i = 0; i < n; i++)
    {
        if (times[i].first >= lastEnd)
        {
            count++;
            lastEnd = times[i].second;
        }
    }

    cout << count;
    return 0;
}