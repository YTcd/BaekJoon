#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int A, B, C;
    vector<int> arr(9);

    cin >> A >> B >> C;

    int num = A * B * C;

    while (num > 0)
    {
        int remain = num % 10;
        arr[remain]++;
        num = num / 10;
    }

    for (int i = 0; i <= 9; i++)
    {
        cout << arr[i] << '\n';
    }

    return 0;
}