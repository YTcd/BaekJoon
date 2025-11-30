#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N, X;
    cin >> N >> X;

    vector<int> arr;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        if (num < X)
        {
            arr.push_back(num);
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << ' ';
    }

    return 0;
}