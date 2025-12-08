#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> arr;
    int count;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end());
    for (int i = 0; i < count; i++)
    {
        cout << arr[i] << "\n";
    }

    return 0;
}