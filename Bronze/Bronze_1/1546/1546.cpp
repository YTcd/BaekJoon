#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int count;
    cin >> count;

    int sum = 0;
    int max = 0;

    for (int i = 0; i < count; i++)
    {
        int score;
        cin >> score;
        if (max < score)
        {
            max = score;
        }
        sum += score;
    }

    double fsum = sum;
    double base = max * count;

    cout << fsum / base * 100.0 << endl;

    return 0;
}