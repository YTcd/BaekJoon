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

    vector<int> v;

    for (int i = 0; i < count; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }

    sort(v.begin(), v.end());

    int sum = 0;

    for (int i = 0; i < v.size(); i++) 
    {
        sum += v[i] * (v.size() - i);
    }

    cout << sum;

    return 0;
}