#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int level;
    cin >> level;

    int count = (level + 1) * level / 2;

    vector<int> vec;
    vector<int> memo;

    memo.push_back(0);
    int plus = 2;
    for (int i = 1; i < level; i++)
    {
        memo.push_back(memo[i - 1] + plus);
        plus++;
    }

    for (int i = 0; i < count; i++)
    {
        int number;
        cin >> number;
        vec.push_back(number);
    }

    int currentLevel = memo.size() - 1;

    for (int i = count - level - 1; i >= 0; i--)
    {
        if (i == memo[currentLevel])
        {
            currentLevel--;
        }

        int num = vec[i];
        vec[i] = num + max(vec[i + currentLevel], vec[i + currentLevel + 1]);
    }

    cout << vec[0];

    return 0;
}