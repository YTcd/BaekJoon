#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node
{
    char self;
    char left;
    char right;
};

vector<Node> vec;

int getIndex(char character)
{
    return character - 65;
}

void frontFirst(int index)
{
    cout << vec[index].self;
    if (vec[index].left != '.')
    {
        frontFirst(vec[index].left - 65);
    }

    if (vec[index].right != '.')
    {
        frontFirst(vec[index].right - 65);
    }
}

void middelFirst(int index)
{
    if (vec[index].left != '.')
    {
        middelFirst(vec[index].left - 65);
    }

    cout << vec[index].self;

    if (vec[index].right != '.')
    {
        middelFirst(vec[index].right - 65);
    }
}

void backFirst(int index)
{
    if (vec[index].left != '.')
    {
        backFirst(vec[index].left - 65);
    }

    if (vec[index].right != '.')
    {
        backFirst(vec[index].right - 65);
    }

    cout << vec[index].self;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int Cnt;
    cin >> Cnt;
    vec.resize(Cnt);
    for (int i = 0; i < Cnt; i++)
    {
        char temp1, temp2, temp3;
        cin >> temp1 >> temp2 >> temp3;
        vec[temp1 - 65] = {temp1, '.', '.'};
        if (temp2 != '.')
        {
            vec[temp1 - 65].left = temp2;
        }
        if (temp3 != '.')
        {
            vec[temp1 - 65].right = temp3;
        }
    }

    frontFirst(0);
    cout << '\n';
    middelFirst(0);
    cout << '\n';
    backFirst(0);

    return 0;
}