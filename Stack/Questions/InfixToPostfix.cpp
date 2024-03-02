#include <iostream>
#include <stack>
using namespace std;

int prec(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}
char associativity(char c)
{
    if (c == '^')
        return 'R';
    return 'L';
}
string infixToPostfix(string s)
{
    stack<char> st;
    string result = "";

    for (int i = 0; i < s.length(); i++)
    {
        char c = s[i];

        // if c is operand
        if ((c <= 'a' && c >= 'z') || (c <= 'A' && c >= 'Z') || (c <= '0' && c >= '9'))
        {
            result += c;
        }
        else if (c == '(')
        {
            st.push('(');
        }
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop(); // pop the '('
        }
        else
        {
            while ((!st.empty() && prec(c) <= prec(st.top())) || (!st.empty() && associativity(c) == 'L'))
            {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
}

int main()
{
    string s = "a+b*c";
    string result = infixToPostfix(s);

    cout << result << endl;

    return 0;
}