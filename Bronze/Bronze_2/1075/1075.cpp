#include <iostream> 
using namespace std;
#include <string>
 
int main()
{
    int N, F;
    cin >> N >> F;

    int quotientOfHundred = N / 100 * 100;
    int remainder = quotientOfHundred % F;
    
    if (remainder == 0) {
        cout << "00" << endl;
        return 0;
    }

    int answer = F - remainder;
    
    string strAnswer;
    if (answer < 10) {
        strAnswer = "0" + to_string(answer);
    } else {
        strAnswer = to_string(answer);
    }

    cout << strAnswer << endl;

    return 0;
}