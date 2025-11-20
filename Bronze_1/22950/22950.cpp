#include <iostream>
using namespace std;

int main()
{
    int base; // 자릿수
    cin >> base;

    string number; // 이진수
    int power;     // 2의 지수 (이진수의 자릿수 - 1)
    cin >> number >> power;

    if (power == 0)
    {
        cout << "YES";
        return 0;
    }

    string out = "YES";
    int numLength = number.length();

    bool allZero = (number.find('1') == string::npos);
    if (allZero == true)
    {
        cout << "YES";
        return 0;
    }

    if (base < power)
    {
        cout << "NO";
        return 0;
    }

    for (int i = numLength - 1; i >= numLength - power; i--)
    {
        if (i < 0)
            break;
        if (number[i] == '1')
        {
            out = "NO";
            break;
        }
    }

    cout << out;

    return 0;
}