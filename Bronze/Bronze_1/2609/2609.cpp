#include <iostream>

using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    
    if (A < B)
    {
        swap(A,B);
    }

    int commonDivide;
    int temp1 = A;
    int temp2 = B;
    while (true)
    {
        int num = temp1 % temp2;
        if (num == 0)
        {
            commonDivide = temp2;
            break;
        }
        
        temp1 = temp2;
        temp2 = num;
    }

    cout << commonDivide << endl;
    cout << A * B / commonDivide << endl;

    return 0;
}