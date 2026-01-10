#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int DFS(int maxDepth, int depth, int lastSelection, vector<vector<int>> &vec, vector<vector<int>> &memo)
{
    if (maxDepth == depth)
    {
        if (lastSelection == 0)
        {
            return vec[depth][0];
        }
        else if (lastSelection == 1)
        {
            return vec[depth][1];
        }
        else if (lastSelection == 2)
        {
            return vec[depth][2];
        }
    }

    if (lastSelection == 0)
    {
        int first = memo[depth + 1][1] != 0 ? memo[depth + 1][1] + vec[depth][0] : DFS(maxDepth, depth + 1, 1, vec, memo) + vec[depth][0];
        int second = memo[depth + 1][2] != 0 ? memo[depth + 1][2] + vec[depth][0] : DFS(maxDepth, depth + 1, 2, vec, memo) + vec[depth][0];

        memo[depth][0] = min(first, second);

        return memo[depth][0];
    }
    else if (lastSelection == 1)
    {
        int first = memo[depth + 1][0] != 0 ? memo[depth + 1][0] + vec[depth][1] : DFS(maxDepth, depth + 1, 0, vec, memo) + vec[depth][1];
        int second = memo[depth + 1][2] != 0 ? memo[depth + 1][2] + vec[depth][1] : DFS(maxDepth, depth + 1, 2, vec, memo) + vec[depth][1];

        memo[depth][1] = min(first, second);

        return memo[depth][1];

        return min(first, second);
    }
    else if (lastSelection == 2)
    {
        int first = memo[depth + 1][0] != 0 ? memo[depth + 1][0] + vec[depth][2] : DFS(maxDepth, depth + 1, 0, vec, memo) + vec[depth][2];
        int second = memo[depth + 1][1] != 0 ? memo[depth + 1][1] + vec[depth][2] : DFS(maxDepth, depth + 1, 1, vec, memo) + vec[depth][2];

        memo[depth][2] = min(first, second);

        return memo[depth][2];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<vector<int>> vec(N, vector<int>(3));
    vector<vector<int>> memo(N, vector<int>(3));

    for (int i = 0; i < N; i++)
    {
        int num1, num2, num3;
        cin >> num1 >> num2 >> num3;

        vec[i][0] = num1;
        vec[i][1] = num2;
        vec[i][2] = num3;
    }

    int mini = 1000001;

    mini = min(DFS(N - 1, 0, 0, vec, memo), mini);
    mini = min(DFS(N - 1, 0, 1, vec, memo), mini);
    mini = min(DFS(N - 1, 0, 2, vec, memo), mini);
    cout << mini;

    return 0;
}