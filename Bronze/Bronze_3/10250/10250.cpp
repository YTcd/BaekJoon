#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int count;
    cin >> count;
    vector<string> arr;
    for (int i = 0; i < count; i++)
    {
        int height, width, index;
        cin >> height >> width >> index;

        int quot, remain;
        quot = index / height;
        quot++;

        remain = index % height;
        if (remain == 0)
        {
            remain = height;
            quot--;
        }

        string suffix;
        if (quot < 10)
        {
            suffix = "0" + to_string(quot);
        }
        else
        {
            suffix = to_string(quot);
        }

        string prefix;
        prefix = to_string(remain);

        arr.push_back(prefix + suffix);
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}