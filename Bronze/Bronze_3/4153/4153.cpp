#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<string> arr;
    while (true)
    {
        int A, B, C;
        cin >> A >> B >> C;
        if (C < B)
        {
            swap(C, B);
        }
        if (C < A)
        {
            swap(C, A);
        }
        if (A == 0 && B == 0 && C == 0)
        {
            break;
        }
        if (A * A + B * B == C * C)
        {
            arr.push_back("right");
        }
        else
        {
            arr.push_back("wrong");
        }
    }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}