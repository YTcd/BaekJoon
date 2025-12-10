#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int hasCount;
    cin >> hasCount;
    vector<int> hasVec(20000001, 0);
    for (int i = 0; i < hasCount; i++)
    {
        int temp;
        cin >> temp;
        temp += 10000000;
        hasVec[temp]++;
    }

    int testCount;
    cin >> testCount;
    vector<int> testVec(testCount, 0);
    for (int i = 0; i < testCount; i++)
    {
        int temp;
        cin >> temp;
        temp += 10000000;
        testVec[i] = hasVec[temp];
    }

    for (int i = 0; i < testCount; i++)
    {
        cout << testVec[i] << ' ';
    }

    return 0;
}