#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "Amit";
    stack<char> st;
    int i = 0;
    while (i < str.length())
    {
        st.push(str[i++]);
    }
    // reverse
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}