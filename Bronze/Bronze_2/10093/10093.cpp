#include <iostream> 
using namespace std;
 
int main()
{
    long A, B;
    cin >> A >> B;

    if (A > B) {
        swap(A, B);
    }

    long countOfNumber = B - A - 1;
    int countOfMiddleNumber = countOfNumber <= 0 ? 0 : countOfNumber;

    cout << countOfMiddleNumber << endl;
    for (int i = 0; i < countOfNumber; i++)
    {
        if (i == countOfNumber)
        {
            cout << A + i + 1 << endl;
        }
        else
        {
            cout << A + i + 1 << " ";
        }
    }
    
    return 0;
}
