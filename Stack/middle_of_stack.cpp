#include "Amit's_Stack.h"

int middle_of_stack(Stack &st, int size)
{
    if (st.topIndex() == size / 2)
    {
        return st.top();
    }
    int temp = st.top();
    st.pop();
    int ans = middle_of_stack(st, size);
    st.push(temp);
    return ans;
};

int main()
{

    Stack st(5);
    st.push(12);
    st.push(3);
    st.push(-5);
    st.push(5);
    st.push(9);

    // middle of the stack
    int x = middle_of_stack(st, st.sizeOfStack());
    cout << x << endl;
}