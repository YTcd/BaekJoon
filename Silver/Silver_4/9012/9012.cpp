#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> result;
    int count;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        string problem;
        cin >> problem;

        int count = 0;

        for (int i = 0; i < problem.length(); i++)
        {
            char c = problem[i];
            if (c == '(')
            {
                count++;
            }
            else if (c == ')')
            {
                count--;
            }

            if (count < 0)
            {
                break;
            }
        }

        count == 0 ? result.push_back("YES") : result.push_back("NO");
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}