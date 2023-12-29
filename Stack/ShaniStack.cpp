#include "Shani's_Stack.h"
int main()
{

    Stack st(5);
    st.push(12);
    st.push(17);
    st.push(6);
    st.push(9);
    st.push(12);

    st.printStack();
    return 0;
}