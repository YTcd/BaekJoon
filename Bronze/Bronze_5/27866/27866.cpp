#include <iostream>
using namespace std;

int main()
{
    string str;
    int index;

    cin >> str >> index;

    cout << str.at(--index);

    return 0;
}