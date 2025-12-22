#include <iostream>
#include <vector>

using namespace std;

struct NodeStruct {
    int val;
    bool checked;
};

void checkAll(vector<vector<NodeStruct>>& board, int row, int col);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int testCaseCount;
    cin >> testCaseCount;

    vector<int> result;

    for (int i = 0 ; i < testCaseCount; i++)
    {
        int row, col;
        cin >> row >> col;

        int count;
        cin >> count;

        vector<vector<NodeStruct>> board(row, vector<NodeStruct>(col, {0, false}));

        for (int j = 0; j < count; j++)
        {
            int x,y;
            cin >> x >> y;
            board[x][y].val = 1;
        }

        int sum = 0;

        for (int j = 0; j < row; j++)
        {
            for (int k = 0; k < col; k++)
            {
                if (board[j][k].val != 0 && board[j][k].checked == false)
                {
                    checkAll(board, j, k);
                    sum++;
                }
            }
        }
        result.push_back(sum);   
    }

    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << '\n';
    }
    return 0;
}

void checkAll(vector<vector<NodeStruct>>& board, int row, int col)
{
    if (row < 0 || row >= board.size() ||
        col < 0 || col >= board[0].size() ||
        board[row][col].val == 0 ||
        board[row][col].checked == true)
    {
        return;
    }

    board[row][col].checked = true;
    checkAll(board, row-1, col);
    checkAll(board, row+1, col);
    checkAll(board, row, col-1);
    checkAll(board, row, col+1);
}