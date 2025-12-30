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
    vector<int> vec;
    vector<int> sorted;

    for (int i = 0; i < count; i++)
    {
        int temp;
        cin >> temp;
        vec.push_back(temp);
        sorted.push_back(temp);
    }

    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

    for (int i = 0; i < count; i++)
    {
        cout << lower_bound(sorted.begin(), sorted.end(), vec[i]) - sorted.begin();
        if (i != count-1)
        {
            cout << ' ';
        }
    }
    

    return 0;
}