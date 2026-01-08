#include <iostream>
#include <vector>

using namespace std;

int N, M;
int arr[9];

void dfs(int start, int depth)
{
    if (depth == M)
    {
        for (int i = 0; i < M; i++)
        {
            cout << arr[i] << ' ';
        }
        cout << "\n";
        return;
    }

    for (int i = start; i <= N; i++)
    {
        arr[depth] = i;
        dfs(i + 1, depth + 1);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    dfs(1, 0);

    return 0;
}