#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int DFS(int Num, vector<int> &vec, int &count);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int Num;
    cin >> Num;

    vector<int> vec(1000000, -1);
    vec[0] = 0;
    vec[1] = 1;
    vec[2] = 1;

    int count = 0;

    DFS(Num, vec, count);
    cout << count;

    return 0;
}

int DFS(int Num, vector<int> &vec, int &count)
{
    if (Num == 1)
    {
        return 0;
    }
    else if (Num == 2 || Num == 3)
    {
        count++;
        return 1;
    }

    count++;
    if (Num % 3 == 0)
    {
        return vec[Num - 1] != -1 ? vec[Num - 1] : DFS(Num / 3, vec, count);
    }
    if (Num % 2 == 0)
    {
        return vec[Num - 1] != -1 ? vec[Num - 1] : DFS(Num / 2, vec, count);
    }

    if (Num % 3 != 1 && Num % 2 != 0)
    {
        return DFS(Num - 1, vec, count);
    }
}