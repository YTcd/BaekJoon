#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int ver, hor;
    cin >> ver >> hor;

    vector<bool> vertical(ver, false);
    vector<bool> horizontal(hor, false);

    for (int i = 0; i < ver; i++)
    {
        string line;
        cin >> line;
        for (int j = 0; j < hor; j++)
        {
            char cell = line[j];
            if (cell == 'X')
            {
                vertical[i] = true;
                horizontal[j] = true;
            }
        }
    }

    int ver_count = 0;
    int hor_count = 0;

    for (int i = 0; i < ver; i++)
    {
        if (!vertical[i])
        {
            ver_count++;
        }
    }

    for (int j = 0; j < hor; j++)
    {
        if (!horizontal[j])
        {
            hor_count++;
        }
    }

    cout << max(ver_count, hor_count) << endl;

    return 0;
}