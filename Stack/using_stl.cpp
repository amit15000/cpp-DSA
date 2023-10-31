#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;
    st.push(12);
    st.push(23);
    st.push(35);
    st.push(-23);

    while (st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}