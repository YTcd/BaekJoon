#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int numCount, hapCount;
    cin >> numCount >> hapCount;

    vector<int> sums(100001, 0);
    sums[0] = 0;
    vector<int> result;

    for (int i = 1; i <= numCount; i++)
    {
        int num;
        cin >> num;
        sums[i + 1] += sums[i] + num;
    }

    for (int c = 0; c < hapCount; c++)
    {
        int i, j;
        cin >> i >> j;
        
        int sum = sums[j + 1] - sums[i];
        result.push_back(sum);
    }
    
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << '\n';
    }
    
    return 0;
}