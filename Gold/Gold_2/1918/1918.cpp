#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    cin >> input;
    stack<char> calculator;

    string answer = "";
    int length = input.length();
    for (int i = 0; i < length; i++)
    {
        char c = input[i];
        if (c >= 'A' && c <= 'Z')
        {
            answer += c;
        }
        else if (c == '(')
        {
            calculator.push(c);
        }
        else if (c == ')')
        {
            while (calculator.top() != '(')
            {
                answer += calculator.top();
                calculator.pop();
            }
            calculator.pop();
        }
        else if (c == '*' || c == '/')
        {
            if (calculator.empty() == false)
            {
                char top = calculator.top();
                if (top == '*' || top == '/')
                {
                    while (calculator.empty() == false &&
                           (calculator.top() == '*' || calculator.top() == '/'))
                    {
                        answer += calculator.top();
                        calculator.pop();
                    }
                }
            }
            calculator.push(c);
        }
        else if (c == '+' || c == '-')
        {
            if (calculator.empty() == false)
            {
                char top = calculator.top();
                if (top == '*' || top == '/' || top == '+' || top == '-')
                {
                    while (calculator.empty() == false &&
                           (calculator.top() == '*' || calculator.top() == '/' ||
                            calculator.top() == '+' || calculator.top() == '-'))
                    {
                        answer += calculator.top();
                        calculator.pop();
                    }
                };
            }
            calculator.push(c);
        }
    }
    while (calculator.empty() == false)
    {
        answer += calculator.top();
        calculator.pop();
    }

    cout << answer;

    return 0;
}