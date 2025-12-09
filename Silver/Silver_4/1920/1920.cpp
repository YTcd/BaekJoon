#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int count1;
    cin >> count1;
    vector<int> vec;
    for (int i = 0; i < count1; i++)
    {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }

    int count2;
    cin >> count2;

    vector<int> vec2;

    for (int i = 0; i < count2; i++)
    {
        int temp;
        cin >> temp;
        vec2.push_back(temp);
    }

    sort(vec.begin(), vec.end());

    vector<int> vec3(count2, 0);

    for (int i = 0; i < count2; i++)
    {
        int center = count1 / 2;
        cout << binary_search(vec.begin(), vec.end(), vec2[i]) << '\n';
    }

    return 0;
}