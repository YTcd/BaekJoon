#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 2000000000;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int treeCnt; // 1 <= N <= 1,000,000
    cin >> treeCnt;

    int bringDist; // 1 <= N <= 2,000,000,000
    cin >> bringDist;

    vector<int> trees;
    for (int i = 0; i < treeCnt; i++)
    {
        int tree;
        cin >> tree;
        trees.push_back(tree);
    }

    sort(trees.begin(), trees.end());

    int low = 0;
    int high = trees[treeCnt - 1];

    int answer = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        long long sum = 0;
        for (int i = 0; i < treeCnt; i++)
        {
            if (trees[i] > mid)
            {
                sum += trees[i] - mid;
            }
        }

        if (sum >= bringDist)
        {
            low = mid + 1;
            answer = mid;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << answer;

    return 0;
}