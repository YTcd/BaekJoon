#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    const long long MOD = 1234567891;
    const long long R = 31;

    int L;
    string s;
    cin >> L >> s;

    long long hash = 0;
    long long power = 1;

    for (int i = 0; i < L; i++)
    {
        long long val = s[i] - 'a' + 1;
        hash = (hash + val * power) % MOD;
        power = (power * R) % MOD;
    }

    cout << hash << '\n';
    return 0;
}