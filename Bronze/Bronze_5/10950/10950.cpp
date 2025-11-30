#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int count;
    vector<int> arr;
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        int A, B;
        cin >> A >> B;
        arr.push_back(A + B);
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << '\n';
    }
    return 0;
}