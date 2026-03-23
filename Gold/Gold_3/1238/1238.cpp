#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct nodeInfo
{
    vector<pair<int, int>> links;
};

struct cmp
{
    bool operator()(pair<int, int>& a, pair<int, int>& b) { return a.first > b.first; }
};

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

    vector<int> dijkTo(studentCnt + 1, INT_MAX);

    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    // 목적지에서의 거리부터 구해두기
    dijkTo[partyLocation] = 0;
    pq.push({0, partyLocation});
    while (pq.empty() == false)
    {
        pair<int, int> top = pq.top();
        pq.pop();
        int costOfCurrent = top.first;
        int currentPos = top.second;
        if (costOfCurrent > dijkTo[currentPos])
        {
            continue;
        }

        for (int i = 1; i < studentCnt + 1; i++)
        {
            // vec[currentPos]는 currentPos 와 있는 곳들의 cost
            if (vec[currentPos][i] == -1)
            {
                continue;
            }
            else if (costOfCurrent + vec[currentPos][i] < dijkTo[i])
            {
                dijkTo[i] = costOfCurrent + vec[currentPos][i];
                pq.push({dijkTo[i], i});
            }
        }
    }

    // 새로 초기화 (비우기)
    pq = priority_queue<pair<int, int>, vector<pair<int, int>>, cmp>();

    vector<int> dijkFrom(studentCnt + 1, INT_MAX);

    dijkFrom[partyLocation] = 0;
    pq.push({0, partyLocation});
    while (pq.empty() == false)
    {
        pair<int, int> top = pq.top();
        pq.pop();
        int costOfCurrnet = top.first;
        int currentPos = top.second;

        if (costOfCurrnet > dijkFrom[currentPos])
        {
            continue;
        }

        for (int i = 1; i < studentCnt + 1; i++)
        {
            if (vec[i][currentPos] == -1)
            {
                continue;
            }
            else if (costOfCurrnet + vec[i][currentPos] < dijkFrom[i])
            {
                dijkFrom[i] = costOfCurrnet + vec[i][currentPos];
                pq.push({dijkFrom[i], i});
            }
        }
    }

    int Max = 0;
    for (int i = 1; i < studentCnt + 1; i++)
    {
        Max = max(Max, dijkFrom[i] + dijkTo[i]);
    }

    cout << Max;

    return 0;
}