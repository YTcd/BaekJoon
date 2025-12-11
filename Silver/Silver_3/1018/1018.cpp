#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> extractBoard(vector<string> board, int x, int y);
int searchBoard(vector<string> board);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int width, height;
    cin >> height >> width;

    vector<string> board;

    for (int i = 0; i < height; i++)
    {
        string lines;
        cin >> lines;
        board.push_back(lines);
    }

    int horRound = width - 7;
    int verRound = height - 7;

    int minimum = 65;

    for (int i = 0; i < verRound; i++)
    {
        for (int j = 0; j < horRound; j++)
        {
            vector<string> extractedBoard = extractBoard(board, i, j);
            int count = searchBoard(extractedBoard);
            minimum = min(count, minimum);
        }
    }

    cout << minimum;

    return 0;
}

vector<string> extractBoard(vector<string> board, int x, int y)
{
    vector<string> temp;
    for (int i = x; i < x + 8; i++)
    {
        temp.push_back(board[i].substr(y, 8));
    }

    return temp;
}

int searchBoard(vector<string> board)
{
    int firstCount = 0;
    int secondCount = 0;

    char first = 'B';
    char second = 'W';

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (i % 2 == 0)
            {
                if (j % 2 == 0)
                {
                    if (board[i][j] != first)
                    {
                        firstCount++;
                    }
                    else if (board[i][j] != second)
                    {
                        secondCount++;
                    }
                }
                else
                {
                    if (board[i][j] == first)
                    {
                        firstCount++;
                    }
                    else if (board[i][j] == second)
                    {
                        secondCount++;
                    }
                }
            }
            else
            {
                if (j % 2 == 0)
                {
                    if (board[i][j] == first)
                    {
                        firstCount++;
                    }
                    else if (board[i][j] == second)
                    {
                        secondCount++;
                    }
                }
                else
                {
                    if (board[i][j] != first)
                    {
                        firstCount++;
                    }
                    else if (board[i][j] != second)
                    {
                        secondCount++;
                    }
                }
            }
        }
    }

    return min(firstCount, secondCount);
}