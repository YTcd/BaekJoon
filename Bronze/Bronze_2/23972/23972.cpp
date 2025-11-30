#include <iostream> 
using namespace std;
 
int main()
{
    long K, N;
    cin >> K >> N;

    if (N == 1)
    {
        cout << -1 << endl;
        return 0;
    }

    long returnAmount = K * N; 

    long result = K * N / (N - 1);
    result = (K * N % (N - 1)) > 0 ? result + 1 : result;
    cout << result << endl;
    return 0;
}
