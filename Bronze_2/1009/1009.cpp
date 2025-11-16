#include <iostream> 
using namespace std;
 
int main()
{
    int caseCount;
    cin >> caseCount;
    for (int i = 0; i < caseCount; i++)
    {
        int a, b;
        cin >> a >> b;
        int numberOfFirstDigits = a % 10;
        switch (numberOfFirstDigits) 
        {
        case 0:
            cout << 10 << "\n";
            break;
        case 1:
            cout << 1 << "\n";
            break;
        case 2:
            if (b % 4 == 0)
                cout << 6 << "\n";
            else if (b % 4 == 1)
                cout << 2 << "\n";
            else if (b % 4 == 2)
                cout << 4 << "\n";
            else
                cout << 8 << "\n";
            break;
        case 3:
            if (b % 4 == 0)
                cout << 1 << "\n";
            else if (b % 4 == 1)
                cout << 3 << "\n";
            else if (b % 4 == 2)
                cout << 9 << "\n";
            else if (b % 4 == 3)
                cout << 7 << "\n";
            break;
        case 4:
            if (b % 2 == 0)
                cout << 6 << "\n";
            else if (b % 2 == 1)
                cout << 4 << "\n";
            break;
        case 5:
                cout << 5 << "\n";
                break;
        case 6:
                cout << 6 << "\n"; 
            break;
        case 7:
            if (b % 4 == 0)
                cout << 1 << "\n";
            else if (b % 4 == 1)
                cout << 7 << "\n";
            else if (b % 4 == 2)
                cout << 9 << "\n";
            else if (b % 4 == 3)
                cout << 3 << "\n";
            break;
        case 8:
            if (b % 4 == 0)
                cout << 6 << "\n";
            else if (b % 4 == 1)
                cout << 8 << "\n";
            else if (b % 4 == 2)
                cout << 4 << "\n";
            else if (b % 4 == 3)
                cout << 2 << "\n";
            break;
        case 9:
            if (b % 2 == 0)
                cout << 1 << "\n";
            else if (b % 2 == 1)
                cout << 9 << "\n";
            break;
        default:
            break;
        }
    }

    return 0;
}