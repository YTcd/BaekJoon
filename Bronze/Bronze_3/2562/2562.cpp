#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int num;
    vector<int> arr;
    while (cin >> num)
    {
        arr.push_back(num);
    }

    int index = -1;
    int max = -1;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            index = i + 1;
        }
    }

    cout << max << '\n'
         << index;

    return 0;
}