#include <iostream>
using namespace std;

int main()
{
    int count;
    cin >> count;
    int min = 1000001;
    int max = -1000001;

    int num;
    while (cin >> num)
    {
        if (num > max)
        {
            max = num;
        }

        if (num < min)
        {
            min = num;
        }
    }

    cout << min << " " << max;

    return 0;
}