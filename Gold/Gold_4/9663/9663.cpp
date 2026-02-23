#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int sizeOfN;
int result = 0;

vector<bool> col;
vector<bool> diag1;  // row + col
vector<bool> diag2;  // row - col

void DFS(int row)
{
    if (row == sizeOfN)
    {
        result++;
        return;
    }

    for (int i = 0; i < sizeOfN; i++)
    {
        if (col[i] == false && diag1[i + row] == false && diag2[row - i + sizeOfN] == false)
        {
            col[i] = true;
            diag1[i + row] = true;
            diag2[row - i + sizeOfN] = true;
            DFS(row + 1);
            col[i] = false;
            diag1[i + row] = false;
            diag2[row - i + sizeOfN] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> sizeOfN;

    col.resize(sizeOfN);
    diag1.resize(sizeOfN * 2);
    diag2.resize(sizeOfN * 2);
    fill(col.begin(), col.end(), false);
    fill(diag1.begin(), diag1.end(), false);
    fill(diag2.begin(), diag2.end(), false);

    DFS(0);

    cout << result;

    return 0;
}