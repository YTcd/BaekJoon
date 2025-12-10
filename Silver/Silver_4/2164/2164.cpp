#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int count;
    cin >> count;

    queue<int> q;
    for (int i = 1; i <= count; i++)
    {
        q.push(i);
    }

    int size = q.size();
    while (size != 1)
    {
        if (size > 1)
        {
            q.pop();
        }

        int a = q.front();
        q.push(a);
        q.pop();
        size = q.size();
    }

    cout << q.front() << '\n';

    return 0;
}