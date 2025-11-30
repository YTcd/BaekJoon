#include <iostream>
using namespace std;

int main()
{
    int countOfPoints;
    cin >> countOfPoints;
    int (*points)[3] = new int[countOfPoints][3];
    for (int i = 0; i < countOfPoints; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        points[i][0] = x;
        points[i][1] = y;
        points[i][2] = z;
    }

    int queryCount;
    cin >> queryCount;
    int *results = new int[queryCount];
    for (int i = 0; i < queryCount; i++)
    {
        int x, y, z;
        long long r;
        cin >> x >> y >> z >> r;
        int insideCount = 0;

        for (int j = 0; j < countOfPoints; j++)
        {
            long long dx = points[j][0] - x;
            long long dy = points[j][1] - y;
            long long dz = points[j][2] - z;
            if (dx * dx + dy * dy + dz * dz <= r * r)
            {
                insideCount++;
            }
        }

        results[i] = insideCount;
    }

    for (int i = 0; i < queryCount; i++)
    {
        cout << results[i] << "\n";
    }

    return 0;
}