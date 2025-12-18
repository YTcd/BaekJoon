#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int Num;
    cin >> Num;

    vector<int> vec(Num + 1, -1);
    vec[0] = 0;
    vec[1] = 0;
    vec[2] = 1;
    vec[3] = 1;

    for (int i = 3; i <= Num; i++)
    {
        if (i * 3 <= Num)
        {
            if (vec[i * 3] == -1)
                vec[i * 3] = vec[i] + 1;
            else
                vec[i * 3] = min(vec[i * 3], vec[i] + 1);
        }

        if (i * 2 <= Num)
        {
            if (vec[i * 2] == -1)
                vec[i * 2] = vec[i] + 1;
            else
                vec[i * 2] = min(vec[i * 2], vec[i] + 1);
        }

        if (i + 1 <= Num)
        {
            if (vec[i + 1] == -1)
                vec[i + 1] = vec[i] + 1;
            else
                vec[i + 1] = min(vec[i + 1], vec[i] + 1);
        }
    }

    cout << vec[Num];

    return 0;
}