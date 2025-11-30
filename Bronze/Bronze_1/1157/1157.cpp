#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string word;
    cin >> word;
    vector<int> alphabet(26, 0);

    for (char c : word)
    {
        if (c - 'a' >= 0 && c - 'a' < 26)
        {
            alphabet[c - 'a']++;
        }
        else if (c - 'A' >= 0 && c - 'A' < 26)
        {
            alphabet[c - 'A']++;
        }
    }

    int max_count = -1;
    char result_char;

    for (int i = 0; i < 26; i++)
    {
        if (alphabet[i] > max_count)
        {
            max_count = alphabet[i];
            result_char = 'A' + i;
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (i != (result_char - 'A') && alphabet[i] == max_count)
        {
            cout << "?" << endl;
            return 0;
        }
    }

    cout << result_char << endl;

    return 0;
}