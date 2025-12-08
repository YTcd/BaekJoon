#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Coordinate
{
    int x;
    int y;
};

bool compare(const Coordinate &a, const Coordinate &b)
{
    if (a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int count;
    cin >> count;

    vector<Coordinate> vec(count);

    for (int i = 0; i < count; i++)
    {
        cin >> vec[i].x >> vec[i].y;
    }

    stable_sort(vec.begin(), vec.end(), compare);

    for (auto &p : vec)
    {
        cout << p.x << " " << p.y << "\n";
    }

    return 0;
}