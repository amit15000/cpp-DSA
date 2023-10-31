#include <bits/stdc++.h>
using namespace std;

int get_middle_of_Stack(stack<int> &st, int original_size)
{
    if (original_size == 0)
    {
        cout << "No element in stack" << endl;
        return -1;
    }
    {
        return st.top();
    }

    if (st.size() - 1 == original_size / 2)
    {
        return st.top();
    }

    int temp = st.top();
    st.pop();
    int ans = get_middle_of_Stack(st, original_size);
    st.push(temp);
    return ans;
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
    int mid = get_middle_of_Stack(st, st.size());
    cout << mid << endl;
    return 0;
}