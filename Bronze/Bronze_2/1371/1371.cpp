#include <iostream> 
using namespace std;
 
int main()
{
    string s, all;
    int count[26] = {0};
    while (getline(cin, s))
    {
        all += s;
    };
    
    for (int i = 0; i < all.length(); i++)
    {
        char word = all.at(i);
        int ascii = word;
        if (ascii >= 97 && ascii < 123)
        {
            count[ascii - 97]++;
        }
    }

    int maxVal = count[0];
   
    for (int i = 0; i < 26; i++)
    {
        if (count[i] > maxVal)
        {
            maxVal = count[i];
        }
    }

    for (int i = 0; i < 26; i++)
    {
        if (count[i] == maxVal)
        {
            char letter = i + 97;
            cout << letter;
        }
    }


    return 0;
}
