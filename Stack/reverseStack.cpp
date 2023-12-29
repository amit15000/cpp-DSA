// return the address of the string
char *reverse(char *S, int len)
{
    stack<char> st;
    int i = 0;
    while (i < len)
    {
        st.push(S[i++]);
    }
    i = 0;
    while (!st.empty())
    {
        S[i++] = st.top();
        st.pop();
    }
    return S;
}