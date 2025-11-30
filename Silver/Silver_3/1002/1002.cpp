#include <iostream> 
using namespace std;
 
int main()
{
    int countOfPrblem;
    cin >> countOfPrblem;
    for (int i = 0; i < countOfPrblem; i++)
    {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        
        if (x1 == x2 && y1 == y2 && r1 == r2)
        {
            cout << -1 << "\n";
            continue;
        }

        int distSquare = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        int rSum = (r1 + r2) * (r1 + r2);
        int rSub = (r1 - r2) * (r1 - r2);

        if (distSquare > rSum)
        {
            cout << 0 << "\n";
        }
        else if (distSquare == rSum)
        {
            cout << 1 << "\n";
        }
        else // distSquare < rSum 인 경우
        {
            if (distSquare < rSub) // 한 원이 다른 원의 내부에 있을 때 (접하지 않음)
            {
                cout << 0 << "\n";
            }
            else if (distSquare == rSub) // 내접할 때
            {
                cout << 1 << "\n";
            }
            else // 두 점에서 만날 때
            {
                cout << 2 << "\n";
            }
        }
    }

    return 0;
}