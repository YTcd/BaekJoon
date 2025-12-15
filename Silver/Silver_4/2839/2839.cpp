#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int kilo;
    cin >> kilo;

    int mok = kilo / 5;
    int nmg = kilo % 5;

    if (kilo % 5 == 0)
    {
        cout << kilo / 5;
    }
    else if (kilo %  5 == 1)
    {
        if (mok < 1)
            cout << -1;
        else
            cout << mok + 1;
    }
    else if (kilo % 5 == 2)
    {
        if (mok < 2)
            cout << -1;
        else
            cout << mok + 2;
    }
    else if (kilo % 5 == 3)
    {
        cout << mok + 1;
    }
    else if (kilo % 5 == 4)
    {
        if (mok < 1)
            cout << -1;
        else
            cout << mok + 2;
    }
    
    return 0;
}