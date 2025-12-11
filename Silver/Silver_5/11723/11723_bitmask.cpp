#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

enum Operation
{
    ADD,
    REMOVE,
    CHECK,
    TOGGLE,
    ALL,
    EMPTY,
    INVALID
};

Operation string_to_operation(const std::string &s)
{
    if (s == "add")
        return Operation::ADD;
    if (s == "remove")
        return Operation::REMOVE;
    if (s == "check")
        return Operation::CHECK;
    if (s == "toggle")
        return Operation::TOGGLE;
    if (s == "all")
        return Operation::ALL;
    if (s == "empty")
        return Operation::EMPTY;
    return Operation::INVALID;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int count;
    cin >> count;

    vector<bool> vec(20, false);
    vector<bool> operations;

    for (int i = 0; i < count; i++)
    {
        string operation;
        int number;

        cin >> operation;
        if (operation != "all" && operation != "empty")
        {
            cin >> number;
            number--;
        }

        switch (string_to_operation(operation))
        {
        case Operation::ADD:
            vec[number] = true;
            break;
        case Operation::REMOVE:
            vec[number] = false;
            break;
        case Operation::CHECK:
            if (vec[number])
                operations.push_back(1);
            else
                operations.push_back(0);
            break;
        case Operation::TOGGLE:
            vec[number] = !vec[number];
            break;
        case Operation::ALL:
            fill(vec.begin(), vec.end(), true);
            break;
        case Operation::EMPTY:
            fill(vec.begin(), vec.end(), false);
            break;
        case Operation::INVALID:
            break;
        }
    }

    for (int i = 0; i < operations.size(); i++)
    {
        cout << operations[i] << '\n';
    }

    return 0;
}