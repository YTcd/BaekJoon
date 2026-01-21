#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int count = 0;
    while (N >= 5) {
        N /= 5;
        count += N;
    }
    cout << count;

    return 0;
}