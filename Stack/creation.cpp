#include <bits/stdc++.h>
using namespace std;

class Stack
{

public:
    int *arr = NULL;
    int size;
    int top;

    // constructor
    Stack(int max_size)
    {
        arr = new int[max_size];
        size = max_size;
        top = -1;
    }

    // methods

    void push(int val)
    {
        // check if stack is full
        if (top == size - 1)
        {
            cout << "Stack is full";
            return;
        }

        top++;
        arr[top] = val;
    }

    void pop()
    {
        // check if stack is empty
        if (top == -1)
        {
            cout << "Stack is empty";
            return;
        }

        top--;
    }

    bool isEmpty()
    {
        if (top == -1)
            return 1;
    }
    bool isFull()
    {
        if (top == size - 1)
            return 1;
    }

    int peek()
    {
        return arr[top];
    }
    void printStack()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
{
    Stack st(5);
    st.push(10);
    st.push(3);
    st.push(6);
    st.push(10);
    st.push(8);
    st.pop();
    st.push(1);
    st.printStack();
    return 0;
}