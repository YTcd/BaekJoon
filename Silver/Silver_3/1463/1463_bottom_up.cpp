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

    int INFI = 1e9;
    vector<int> vec(Num + 1, INFI);
    vec[0] = 0;
    vec[1] = 0;

    for (int i = 1; i <= Num; i++)
    {

        vec[i] = min(vec[i - 1] + 1, vec[i]);

        if (i % 3 == 0)
        {
            vec[i] = min(vec[i / 3] + 1, vec[i]);
        }

        if (i % 2 == 0)
        {
            vec[i] = min(vec[i / 2] + 1, vec[i]);
        }
    }

    cout << vec[Num];

    return 0;
}