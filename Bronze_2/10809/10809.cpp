#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int* arr = new int[26];
    fill(arr, arr+26, -1);

    for (int i = 0; i < str.length(); i++)
    {
        char character = str.at(i);
        if (arr[character-'a'] == -1)
        {
            arr[character-'a'] = i;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        cout << arr[i] << ' ';
    }
    

    return 0;
}