#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    int result = 0;
    for (int i = 1; i < n; i++) {
        int num = i;
        int sum = num;
        while(num > 0)
        {
            sum += num % 10;
            num /= 10;
        }
        if (sum == n) {
            result = i;
            break;
        }
    }

    cout << result;
    

    return 0;
}