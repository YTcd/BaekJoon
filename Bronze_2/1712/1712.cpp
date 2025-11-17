#include <iostream> 
using namespace std;
 
int main()
{
    int cost, plusCost, price;
    cin >> cost >> plusCost >> price;

    if (price <= plusCost) {
        cout << -1 << endl;
        return 0;
    }

    int plus = price - plusCost;
    
    int makeCount = cost / plus + 1;
    cout << makeCount << endl;
    return 0;
}
