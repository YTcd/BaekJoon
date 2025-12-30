#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct cnt{
    int x;
    int count;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int subin;
    int brother;
    cin >> subin >> brother;

    queue<cnt> que;
    vector<bool> checked(100001);

    que.push({subin, 0});
    checked[subin] = true;
    int count = 0;

    while(que.empty()!= true)
    {
        cnt current = que.front();
        que.pop();
        count = current.count;
        if (current.x == brother)
        {
            break;
        }
        if (current.x + 1 <= 100000 && checked[current.x + 1] == false)
        {
            que.push({current.x + 1, current.count + 1});
            checked[current.x + 1] = true;
        }

        if (current.x * 2 <= 100000 && checked[current.x * 2] == false)
        {
            que.push({current.x * 2, current.count + 1});
            checked[current.x * 2] = true;
        }
        
        if (current.x - 1 >= 0 && checked[current.x - 1] == false)
        {
            que.push({current.x - 1, current.count + 1});
            checked[current.x - 1] = true;
        }
    }

    cout << count;
    
    return 0;
}