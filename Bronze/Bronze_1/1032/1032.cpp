#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int countOfFiles;
    cin >> countOfFiles;

    vector<string> files;

    string fileName;
    while (cin >> fileName)
    {
        files.push_back(fileName);
    }

    int firstItemlength = files[0].size();

    int sizeOfArr = files.size();
    if (sizeOfArr == 1)
    {
        cout << files[0];
        return 0;
    }

    for (int i = 0; i < firstItemlength; i++)
    {
        for (int j = 1; j < sizeOfArr; j++)
        {
            if (files[0].at(i) != files[j].at(i))
            {
                files[0].at(i) = '?';
                break;
            }
        }
    }

    cout << files[0];

    return 0;
}