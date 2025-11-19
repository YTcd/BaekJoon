#include <iostream> 
using namespace std;
 
int main()
{
    int K, N;
    cin >> K >> N;

    if (N == 1)
    {
        cout << -1 << endl;
        return 0;
    }

    int returnAmount = K * N; 

    int result = K * N / (N - 1);
    result = (K * N % (N - 1)) > 0 ? result + 1 : result;
    cout << result << endl;
    return 0;
}
