#include <iostream>
using namespace std;

int main()
{
    int up, down, target;
    cin >> up >> down >> target;
    int days = 0;

    if (up == target)
    {
        cout << 1 << endl;
        return 0;
    }

    int diff = up - down;
    int oneDayLack = target - up;
    int days_to_reach = oneDayLack / diff;

    if (oneDayLack % diff != 0)
    {
        days_to_reach += 1;
    }

    cout << days_to_reach + 1 << endl;

    return 0;
}