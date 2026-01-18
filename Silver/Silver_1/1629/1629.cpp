#include <iostream>

using namespace std;

long long C;

long long POW(long long a, long long b)
{
    if (b == 1)
    {
        return a % C;
    }

    long long temp = POW(a, b / 2);
    temp = (temp * temp) % C;

    if (b % 2 == 1)
    {
        temp = (temp * a) % C;
    }

    return temp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long A, B;
    cin >> A >> B >> C;

    cout << POW(A, B);

    return 0;
}