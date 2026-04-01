#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Cell
{
    int x, y;
    bool broken;
    int dist;
};

queue<Cell> que;

void checkCell(int x, int y, bool broken, int dist, vector<vector<bool>> &map, vector<vector<vector<bool>>> &visited){
    bool isWall = map[x][y];
    if (isWall)
    {
        if (visited[x][y][1] == false)
        {
            if (broken == false)
            {
                visited[x][y][1] = true;
                que.push({x,y, true, dist + 1});
            }
        }
    }
    else
    {
        if (visited[x][y][broken] == false)
        {
            int brokenStatus = broken ? 1 : 0;
            visited[x][y][brokenStatus] = true;
            que.push({x,y, broken, dist + 1});   
        }
    }    
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int colSize, rowSize;

    cin >> colSize >> rowSize;

    vector<vector<bool>> map(colSize, vector<bool>(rowSize));

    for (int i = 0; i < colSize; i++)
    {
        string temp;
        cin >> temp;
        for (int j = 0; j < rowSize; j++)
        {
            int number = temp[j] - '0';
            map[i][j] = number == 1 ? true : false;
        }
    }

    vector<vector<vector<bool>>> visited(
    colSize, vector<vector<bool>>(rowSize, vector<bool>(2, false)));

    visited[0][0][0] = true;
    que.push({0,0,false,1});

    while(!que.empty() == true)
    {
        Cell curPos = que.front();
        que.pop();

        int x = curPos.x;
        int y = curPos.y;

        if (x == colSize-1 && y == rowSize-1)
        {
            cout << curPos.dist << endl;
            return 0;
        }

        // top
        if (y-1 >= 0)
        {
            checkCell(x, y-1, curPos.broken, curPos.dist, map, visited); 
        }

        // bottom
        if (y+1 < rowSize)
        {
            checkCell(x, y+1, curPos.broken, curPos.dist, map, visited);
        }

        // left
        if (x-1 >= 0)
        {
            checkCell(x-1, y, curPos.broken, curPos.dist, map, visited);
        }

        // right
        if (x+1 < colSize)
        {
            checkCell(x+1, y, curPos.broken, curPos.dist, map, visited);
        }
    };

    cout << -1 << endl;
    
    return 0;
}