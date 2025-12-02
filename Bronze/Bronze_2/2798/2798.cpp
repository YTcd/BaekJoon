#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int count, target;
    cin >> count >> target;
    vector<int> numbers;

    for (int i = 0; i < count; i++)
    {
        int number;
        cin >> number;
        if (number < target)
        {
            numbers.push_back(number);
        }
    }

    int max = 0;

    for (int i = 0; i < count; i++)
    {
        for (int j = i + 1; j < count; j++)
        {
            if (i == j)
            {
                continue;
            }
            for (int k = j + 1; k < count; k++)
            {
                if (i == k || j == k)
                {
                    continue;
                }

                int sum = numbers[i] + numbers[j] + numbers[k];
                if (sum == target)
                {
                    cout << sum;
                    return 0;
                }

                if (sum > max && sum < target)
                {
                    max = sum;
                }
            }
        }
    }

    cout << max;

    return 0;
}