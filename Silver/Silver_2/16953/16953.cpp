#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long A, B;
    cin >> A >> B;

    int cnt = 1;
    while (B > A) {
        if (B % 10 == 1) {
            B /= 10;
            cnt++;
        } else if (B % 2 == 0) {
            B /= 2;
            cnt++;
        } else {
            cout << -1;
            return 0;
        }
    }

    cout << (B == A ? cnt : -1);

    return 0;
}