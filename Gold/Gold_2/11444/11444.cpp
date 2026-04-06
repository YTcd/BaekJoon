#include <iostream>

using namespace std;

long long MODULA = 1000000007;

pair<long long, long long> fib(long long n)
{
    if (n == 0)
    {
        return {0, 1};
    }

    auto p = fib(n / 2);
    long long a = p.first;
    long long b = p.second;

    long long c = a * ((2 * b % MODULA - a + MODULA) % MODULA) % MODULA;
    long long d = (a * a % MODULA + b * b % MODULA) % MODULA;

    if (n % 2 == 0)
    {
        return {c, d};
    }
    else
    {
        return {d, (c + d) % MODULA};
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long N;
    cin >> N;

    cout << fib(N).first;

    return 0;
}