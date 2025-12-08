#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int num;
    cin >> num;
    if (num == 1)
    {
        cout << 1;
        return 0;
    }

    int sum = 1;
    int plus = 6;
    int count = 1;

    while (true)
    {
        count++;
        sum += plus;
        if (sum >= num)
            break;
        plus += 6; 
    }
    cout << count;
    return 0;
}