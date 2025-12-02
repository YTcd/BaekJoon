#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int count;
    cin >> count;
    vector<string> arr;
    
    for (int i = 0; i < count; i++)
    {
        string quiz;
        cin >> quiz;
        arr.push_back(quiz);
    }

    for (int i = 0; i < count; i++)
    {
        int score = 1;
        int result = 0;
        for (int j = 0; j < arr[i].length(); j++)
        {
            if (j == 0)
            {
                score = 1;
            }

            if (arr[i].at(j) == 'O')
            {
                result += score;
                score++;
            }
            else if (arr[i].at(j) == 'X')
            {
                score = 1;
            }
            
            if (j == arr[i].length()-1)
            {
                cout << result << endl;
                result = 0;
            }
        }
    }

    return 0;
}