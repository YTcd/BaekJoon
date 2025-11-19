#include <iostream>
using namespace std;

int main()
{
    int countOfNumbers;
    cin >> countOfNumbers;
    int count[10000] = {0};
    size_t size = sizeof(count) / sizeof(count[0]);
    int temp = 0;
    for (int i = 0; i < countOfNumbers; i++)
    {
        cin >> temp;
        count[temp - 1]++;
    }

    for (int j = 0; j < size; j++)
    {
        if (count[j] != 0)
        {
            for (int k = 0; k < count[j]; k++)
            {
                cout << j + 1 << "\n";
            }
        }
    }

    return 0;
}