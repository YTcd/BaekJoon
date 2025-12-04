#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int count;
    cin >> count;
    vector<string> strArr;
    vector<string> sortedArr;

    vector<vector<string>> sizeArr(51);

    for (int i = 0; i < count; i++)
    {
        string str;
        cin >> str;
        strArr.push_back(str);
        int length = str.length();
        sizeArr[length].push_back(str);
    }

    for (int i = 0; i < 51; i++)
    {
        vector<string> eachItem = sizeArr[i];
        sort(eachItem.begin(), eachItem.end());
        eachItem.erase(unique(eachItem.begin(), eachItem.end()), eachItem.end());
        int size = eachItem.size();
        for (int j = 0; j < size; j++)
        {
            sortedArr.push_back(eachItem[j]);
        }
    }

    for (int i = 0; i < sortedArr.size(); i++)
    {
        cout << sortedArr[i] << '\n';
    }

    return 0;
}