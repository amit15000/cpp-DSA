class Solution
{
public:
    void solve(stack<int> &s, int sizeOfStack, int &index)
    {
        if (index == sizeOfStack / 2)
        {
            return s.pop();
        }
        int temp = s.top();
        s.pop();
        index++;
        solve(s, sizeOfStack, index);
        // backtracking
        s.push(temp);
    }
    // Function to delete middle element of a stack.
    void deleteMid(stack<int> &s, int sizeOfStack)
    {
        int index = 0;
        solve(s, sizeOfStack, index);
    }
};

// //method 2
// #include "Amit's_Stack.h"

// void delete_middle_of_stack(Stack &st, int size)
// {
//     if (st.topIndex() == size / 2)
//     {
//         return st.pop();
//     }
//     int temp = st.top();
//     st.pop();
//     delete_middle_of_stack(st, size);
//     st.push(temp);
// };

// int main()
// {

//     Stack st(5);
//     st.push(12);
//     st.push(3);
//     st.push(-5);
//     st.push(5);
//     st.push(9);

//     // middle of the stack
//     delete_middle_of_stack(st, st.sizeOfStack());
//     st.printStack();
// }