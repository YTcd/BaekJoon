#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>

using namespace std;

void MakeResult(const deque<int> &arr, vector<string> &result, bool isRev);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int testCount;
    cin >> testCount;

    vector<string> result;

    for (int i = 0; i < testCount; i++)
    {
        string func;
        cin >> func;

        int count;
        cin >> count;

        string arr;
        cin >> arr;
        int size = arr.size();
        deque<int> deq;

        int num = 0;
        for (int i = 1; i < size - 1; i++)
        {
            if (arr[i] == ',')
            {
                deq.push_back(num);
                num = 0;
            }
            else
            {
                num = num * 10 + (arr[i] - '0');
            }
        }

        if (size > 2)
            deq.push_back(num);

        int funcSize = func.size();
        bool isRev = false;
        bool hasError = false;
        for (int i = 0; i < funcSize; i++)
        {
            char RorD = func[i];
            if (RorD == 'D')
            {
                if (deq.size() == 0)
                {
                    hasError = true;
                    result.push_back("error");
                    break;
                }

                if (isRev)
                {
                    deq.pop_back();
                }
                else
                {
                    deq.pop_front();
                }
            }
            else if (RorD == 'R')
            {
                isRev = !isRev;
            }
        }

        if (hasError == false)
        {
            MakeResult(deq, result, isRev);
        }
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << '\n';
    }

    return 0;
}

void MakeResult(const deque<int> &arr, vector<string> &result, bool isRev)
{
    int size = arr.size();
    string str;
    str.reserve(size * 6 + 2);
    str.push_back('[');
    if (isRev == false)
    {
        for (int i = 0; i < size; i++)
        {
            int num = arr[i];
            str += to_string(num);
            if (i != size - 1)
                str += ",";
        }
    }
    else
    {
        for (int i = size - 1; i >= 0; i--)
        {
            int num = arr[i];
            str += to_string(num);
            if (i != 0)
                str += ",";
        }
    }

    str.push_back(']');
    result.push_back(str);
}