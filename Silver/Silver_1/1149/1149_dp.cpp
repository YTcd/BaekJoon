#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int count;
    cin >> count;

    vector<vector<int>> vec(count, vector<int>(3, 0));
    for (int i = 0; i < count; i++)
    {
        cin >> vec[i][0];
        cin >> vec[i][1];
        cin >> vec[i][2];
    }

    for (int i = 1; i < count; i++)
    {
        vec[i][0] = min(vec[i - 1][1], vec[i - 1][2]) + vec[i][0];
        vec[i][1] = min(vec[i - 1][0], vec[i - 1][2]) + vec[i][1];
        vec[i][2] = min(vec[i - 1][0], vec[i - 1][1]) + vec[i][2];
    }

    int MIN = 1000001;
    MIN = min(MIN, vec[count - 1][0]);
    MIN = min(MIN, vec[count - 1][1]);
    MIN = min(MIN, vec[count - 1][2]);

    cout << MIN;

    return 0;
}