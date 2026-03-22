#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int studentCnt, loadCnt, partyLocation;
    cin >> studentCnt >> loadCnt >> partyLocation;

    vector<vector<int>> vec(studentCnt + 1, vector<int>(studentCnt + 1, -1));

    for (int i = 0; i < loadCnt; i++)
    {
        int startPos, EndPos, cost;

        cin >> startPos >> EndPos >> cost;
        vec[startPos][EndPos] = cost;
    }

    return 0;
}