#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int recursive(int size, int row, int col);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int size, row, col;
    cin >> size >> row >> col;

    int result = recursive(size, row, col);

    cout << result;

    return 0;
}

int recursive(int size, int row, int col)
{
    if (size == 1)
    {
        if (row == 0 && col == 0)
        {
            return 0;
        }
        else if (row == 0 && col == 1)
        {
            return 1;
        }
        else if (row == 1 && col == 0)
        {
            return 2;
        }
        else if (row == 1 && col == 1)
        {
            return 3;
        }
        else
        {
            return 100;
        }
    }

    int half = pow(2, size - 1);

    if (half <= row && half <= col)
    {
        // Right Down
        return recursive(size - 1, row - half, col - half) + pow(half, 2) * 3;
    }
    else if (half <= row && half > col)
    {
        // Right Up
        return recursive(size - 1, row - half, col) + pow(half, 2) * 2;
    }
    else if (half > row && half > col)
    {
        // Left Top
        return recursive(size - 1, row, col);
    }
    else
    {
        // Left Down
        return recursive(size - 1, row, col - half) + pow(half, 2);
    }
}