#include <iostream> 
using namespace std;
 
int main()
{
    string hexadecimal;
    cin >> hexadecimal;

    int decimal = stoi(hexadecimal, nullptr, 16);

    std::cout << decimal << std::endl;
    return 0;
}
