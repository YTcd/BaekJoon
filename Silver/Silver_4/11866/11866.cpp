#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int count;
    cin >> count;

    vector<int> vec;
    for (int i = 0; i < count; i++)
    {
        vec.push_back(i);
    }

    if (vec.size() == 1)
    {
        cout << "<1>";
        return 0;
    }

    int order, index;
    cin >> order;
    index = order - 1;

    string result = "<";

    for (int i = 0; i < count; i++)
    {
        int size = vec.size();
        if (index >= size)
        {
            index %= size;
        }

        int val = vec[index];
        result += to_string(val + 1);
        if (i + 1 == count)
        {
            result += ">";
        }
        else
        {
            result += ", ";
        }
        vec.erase(vec.begin() + index);
        index += order - 1;
    }

    cout << result << endl;

    return 0;
}