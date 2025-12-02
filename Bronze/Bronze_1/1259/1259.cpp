#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<string> result;
    while (true)
    {
        int num;
        cin >> num;
        if (num == 0)
        {
            break;
        }

        string str = to_string(num);
        int length = str.length();

        bool isPalindrome = true;
        for (int i = 0; i < length / 2; i++)
        {
            if (str[i] != str[length - i - 1])
            {
                isPalindrome = false;
                break;
            }
        }
        if (isPalindrome)
        {
            result.push_back("yes");
        }
        else
        {
            result.push_back("no");
        }
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }
    return 0;
}