#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int count;
    vector<string> strArr;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        int repeatCount;
        cin >> repeatCount;
        string str;
        cin >> str;

        string result = "";

        for (int i = 0; i < str.size(); i++)
        {
            char charactor = str.at(i);
            for (int i = 0; i < repeatCount; i++)
            {
                result.push_back(charactor);
            }
        }

        strArr.push_back(result);
    }

    for (int i = 0; i < strArr.size(); i++)
    {
        cout << strArr[i] << endl;
    }

    return 0;
}