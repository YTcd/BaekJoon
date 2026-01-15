#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
vector<int> vec;
int nCount, pCount;
int arr[9];
bool visited[9];

void dfs(int depth)
{
    if (depth == pCount)
    {
        for (int i = 0; i < pCount; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < nCount; i++)
    {
        if (visited[i] != true)
        {
            visited[i] = true;
            arr[depth] = vec[i];
            dfs(depth + 1);
            visited[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> nCount >> pCount;

    for (int i = 0; i < nCount; i++)
    {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }

    sort(vec.begin(), vec.end());

    dfs(0);

    return 0;
}