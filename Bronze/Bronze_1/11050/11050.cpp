#include <iostream>

using namespace std;

int fac(int num)
{
    if (num <= 1)
    {
        return 1;
    }
    return num * fac(num - 1);
}

int main()
{
    int N, K;
    cin >> N >> K;

    int result = fac(N) / (fac(K) * fac(N - K));
    cout << result << endl;
    return 0;
}