#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> result;

    queue<int> que;

    int count;
    cin >> count;

    for (int i = 0; i < count; i++)
    {
        string command;
        cin >> command;
        if (command == "push")
        {
            int num;
            cin >> num;
            que.push(num);
        }
        else if (command == "pop")
        {
            if (que.empty())
            {
                result.push_back(-1);
            }
            else
            {
                result.push_back(que.front());
                que.pop();
            }
        }
        else if (command == "size")
        {
            result.push_back(que.size());
        }
        else if (command == "empty")
        {
            que.empty() ? result.push_back(1) : result.push_back(0);
        }
        else if (command == "front")
        {
            que.empty() ? result.push_back(-1) : result.push_back(que.front());
        }
        else if (command == "back")
        {
            que.empty() ? result.push_back(-1) : result.push_back(que.back());
        }
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << "\n";
    }

    return 0;
}