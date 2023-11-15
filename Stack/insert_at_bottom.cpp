#include "Amit's_Stack.h"
int i = 0;
void insert_at_bottom(Stack &st, int target)
{

    if (st.isEmpty())
    {
        st.push(target);
        return;
    }

    int temp = st.top();

    st.pop();
    insert_at_bottom(st, target);

    st.push(temp);
    return;
}
Stack reverseStack(Stack &st)
{
    if (st.isEmpty())
    {
        return st;
    }
    int target = st.top();
    st.pop();
    reverseStack(st);
    insert_at_bottom(st, target);
    return st;
}

int main()
{
    Stack st(100);
    int i = 1;

    st.push(i++);
    st.push(i++);
    st.push(i++);
    st.push(i++);
    st.push(i++);

    insert_at_bottom(st, 10);
    st.printStack();
    Stack reversed_stack = reverseStack(st);
    reversed_stack.printStack();
    return 0;
}