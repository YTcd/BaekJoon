#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a;
    cin >> a;

    string mul = " * ";
    string nun = " = ";
    for (int i = 1; i <= 9; i++)
    {
        cout << a;
        cout << mul;
        cout << i;
        cout << nun;
        cout << (a * i) << endl;
    }

    return 0;
}