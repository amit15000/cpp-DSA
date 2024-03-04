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
        cout << c << endl;
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
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
            st.pop();
        }
        else
        {

            while ((!st.empty() && prec(c) <= prec(st.top())) && associativity(c) == 'L')
            {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }
    cout << "Operator" << endl;
    while (!st.empty())
    {

        result += st.top();
        st.pop();
    }
    return result;
}

int main()
{
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    string res = infixToPostfix(exp);
    cout << res << endl;
}