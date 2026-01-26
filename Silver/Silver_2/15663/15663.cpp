#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int totalCount, printCount;
int arr[9];
bool visited[9];
vector<int> vec;

void DFS(int depth)
{
    if (depth == printCount)
    {
        for (int i = 0; i < printCount; i++)
        {
            cout << arr[i];
            if (i != printCount - 1)
            {
                cout << ' ';
            }
        }
        cout << '\n';
        return;
    }

    int prev = -1;

    for (int i = 0; i < totalCount; i++)
    {
        if (visited[i] != true && prev != vec[i])
        {
            visited[i] = true;
            arr[depth] = vec[i];
            prev = vec[i];
            DFS(depth + 1);
            visited[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> totalCount >> printCount;

    for (int i = 0; i < totalCount; i++)
    {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }

    sort(vec.begin(), vec.end());

    DFS(0);

    return 0;
}