#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int playerCount;
    cin >> playerCount;

    int s,m,l,xl,xxl,xxxl;
    cin >> s >> m >> l >> xl >> xxl >> xxxl;
    vector<int> arr = {s,m,l,xl,xxl,xxxl};

    int tShirtPerPack, penPerPack;
    cin >> tShirtPerPack >> penPerPack;

    int max = 0;
    int totalCount = 0;

    for (int i = 0; i < 6; i++)
    {
        int temp =  (arr[i] - 1) / tShirtPerPack;
        if (arr[i] > 0)
        {
            temp++;    
        }

        if (temp > max)
        {
            max = temp;
        }
        totalCount += temp;
    }

    int pack = playerCount / penPerPack;
    int each = playerCount % penPerPack;

    cout << totalCount << endl;
    cout << pack << ' ' << each << endl;

    return 0;
}