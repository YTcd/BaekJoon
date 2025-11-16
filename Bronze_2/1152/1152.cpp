#include <iostream> 
using namespace std;
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
 
int main()
{
    string str;
    istringstream ss;
    vector<string> splitedStr;
    getline(cin, str);
    ss.str(str);
    while (ss >> str)
    {
        splitedStr.push_back(str);
    }
    
    cout << splitedStr.size() << endl;

    return 0;
}