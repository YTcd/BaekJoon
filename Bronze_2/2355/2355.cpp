#include <iostream> 
using namespace std;
 
int main()
{
    long A, B;
    cin >> A >> B;

    long sum = 0;

    if (A > B)
    {
        swap(A, B);
    }

    if (A == B)
    {
        cout << A << endl;
        return 0;
    }
    
    sum = (A + B) * (B - A + 1);

    cout << sum / 2<< endl;
    return 0;
}
