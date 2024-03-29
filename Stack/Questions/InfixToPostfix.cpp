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
            st.pop(); // pop the '('
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
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    return result;
}

bool isOperand(char c)
{
    return c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c >= '0' && c <= '9';
}

string getInfix(string exp)
{
    stack<string> s;
    for (int i = 0; exp[i] != '\0'; i++)
    {

        // push operand
        if (isOperand(exp[i]))
        {
            string op(1, exp[i]);
            s.push(op);
        }
        else
        {
            // an operator
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push("(" + op2 + exp[i] + op1 + ")");
        }
    }
    return s.top();
}

int main()
{
    string s = "a+b*(c^d-e)^(f+g*h)-i";
    string result = infixToPostfix(s);

    cout << result << endl;

    cout << getInfix(result) << endl;

    return 0;
}