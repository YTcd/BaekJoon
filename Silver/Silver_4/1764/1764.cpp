#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    map<string, bool> m;
    vector<string> v;
    
    int countL, countS;
    cin >> countL >> countS;
    
    for (int i = 0; i < countL; i++)
    {
        string str;
        cin >> str;
        m[str] = true;
    }
 
    for (int i = 0; i < countS; i++)
    {
        string str;
        cin >> str;
        if (m[str] == true)
        {
            v.push_back(str);
        }
    }

    cout << v.size() << '\n';
    sort(v.begin(), v.end());
    for (auto str: v)
    {
        cout << str << '\n';
    }
    

    return 0;
}