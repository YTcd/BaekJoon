#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int DFS(int Num, vector<int> &vec);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int Num;
    cin >> Num;

    vector<int> vec(1000001, -1);
    vec[0] = 0;
    vec[1] = 0;
    vec[2] = 1;
    vec[3] = 1;

    int count = 0;

    count = DFS(Num, vec);
    cout << count;

    return 0;
}

int DFS(int Num, vector<int> &vec)
{
    if (Num == 1)
    {
        return 0;
    }
    else if (Num == 2 || Num == 3)
    {
        return 1;
    }

    if (vec[Num] != -1)
        return vec[Num];

    int minVal = DFS(Num - 1, vec) + 1;

    if (Num % 2 == 0)
        minVal = min(minVal, DFS(Num / 2, vec) + 1);

    if (Num % 3 == 0)
        minVal = min(minVal, DFS(Num / 3, vec) + 1);

    vec[Num] = minVal;

    return vec[Num];
}