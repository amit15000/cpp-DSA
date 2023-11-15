#include <bits/stdc++.h>
using namespace std;

class Stack
{

private:
    int *arr = NULL;
    int size;
    int TOP;

public:
    // constructor

    Stack(int max_size)
    {
        arr = new int[max_size];
        size = max_size;
        TOP = -1;
    }

    // methods

    void push(int val)
    {
        // check if stack is full
        if (TOP == size - 1)
        {
            cout << "Stack is full";
            return;
        }

        TOP++;
        arr[TOP] = val;
    }

    void pop()
    {
        // check if stack is empty
        if (TOP == -1)
        {
            cout << "Stack is empty";
            return;
        }

        TOP--;
    }

    bool isEmpty()
    {
        if (TOP == -1)
            return 1;
        else
            return 0;
    }
    bool isFull()
    {
        if (TOP == size - 1)
            return 1;
        else
            return 0;
    }

    int top()
    {
        return arr[TOP];
    }
    void printStack()
    {
        for (int i = 0; i <= TOP; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};