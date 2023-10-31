#include <bits/stdc++.h>
using namespace std;

void insert_at_bottom(stack<int> &st, int temp_top)
{
    if (st.size() == 0)
    {
        cout << "Amit" << endl;
        st.push(temp_top);
        return;
    }

    int temp = st.top();
    st.pop();
    insert_at_bottom(st, temp_top);
    st.push(temp);
}
int main()
{

    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.push(70);
    // cout << st.size() << endl;
    insert_at_bottom(st, st.top());
    st.pop();
    while (st.size() != 0)
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}