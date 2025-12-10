#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int> stack;
    vector<int> vec;

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
            stack.push(num);
        }
        else if (command == "pop")
        {
            if (stack.empty())
            {
                vec.push_back(-1);
            }
            else
            {

                vec.push_back(stack.top());
                stack.pop();
            }
        }
        else if (command == "size")
        {
            vec.push_back(stack.size());
        }
        else if (command == "empty")
        {
            stack.empty() ? vec.push_back(1) : vec.push_back(0);
        }
        else if (command == "top")
        {
            stack.empty() ? vec.push_back(-1) : vec.push_back(stack.top());
        }
    }

    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << '\n';
    }

    return 0;
}