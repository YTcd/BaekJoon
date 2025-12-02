#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int count;
    cin >> count;
    if (count < 1)
    {
        cout << "0";
        return 0;
    }

    vector<int> numbers;
    int countOfPrime = 0;

    for (int i = 0; i < count; i++)
    {
        int number;
        cin >> number;
        numbers.push_back(number);
    }

    for (int i = 0; i < count; i++)
    {
        if (numbers[i] != 1)
        {
            bool isPrime = true;

            for (int j = 2; j < numbers[i]; j++)
            {
                if (numbers[i] % j == 0)
                {
                    isPrime = false;
                    break;
                }
            }

            if (isPrime)
            {
                countOfPrime++;
            }
        }
    }

    cout << countOfPrime;

    return 0;
}