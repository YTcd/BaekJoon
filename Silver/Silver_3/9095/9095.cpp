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

    vector<int> result;
    result.push_back(1);
    result.push_back(2);
    result.push_back(4);
    result.push_back(7);

    for (int i = 4; i < 11; i++)
    {
        result.push_back(result[i - 1] + result[i - 2] + result[i - 3]);
    }

    vector<int> answer;

    for (int i = 0; i < count; i++)
    {
        int num;
        cin >> num;
        answer.push_back(result[num - 1]);
    }

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << '\n';
    }

    return 0;
}