#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr;
    for (int i = 0; i < 8; i++)
    {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    
    bool isAscending = true;
    bool isDescending = true;

    for (int i = 0; i < 8; i++)
    {
        if (arr[i] != i+1)
        {
            isAscending = false;
        }
        
        if (arr[i] != 8-i)
        {
            isDescending = false;
        }
    }

    if (isAscending)
    {
        cout << "ascending";
    }
    else if (isDescending)
    {
        cout << "descending";
    }
    else
    {
        cout << "mixed";
    }
    

    return 0;
}