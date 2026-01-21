#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string isbn;
    cin >> isbn;

    int sum = 0;
    int starPos = -1;

    for (int i = 0; i < 13; i++)
    {
        if (isbn[i] == '*')
        {
            starPos = i;
            continue;
        }

        int num = isbn[i] - '0';

        if (i % 2 == 0)
            sum += num;
        else
            sum += num * 3;
    }

    int need = (10 - (sum % 10)) % 10;

    if (starPos == 12)
    {
        cout << need;
        return 0;
    }

    int weight = (starPos % 2 == 0) ? 1 : 3;

    for (int x = 0; x <= 9; x++)
    {
        if ((x * weight) % 10 == need)
        {
            cout << x;
            return 0;
        }
    }
}
