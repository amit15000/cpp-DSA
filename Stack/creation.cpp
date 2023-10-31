#include <bits/stdc++.h>
using namespace std;

class Stack
{

public:
    // properties
    int *arr;
    int size;
    int top;

    // behavior or method

    // constructor

    Stack(int size)
    {
        arr = new int[size];
        top = -1;
    }

    void push(int _val)
    {
        // check for overflow
        if (top >= size - 1)
        {
            cout << "Stack overflow" << endl;
            return;
        }

        top++;
        arr[top] = _val;
    }

    void pop()
    {

        if (top <= -1)
        {
            cout << "Underflow" << endl;
        }
        top--;
    }

    bool peek()
    {
        return arr[top];
    }
    bool empty()
    {
        if (top <= -1)
            return 1;
        return 0;
    }

    void print()
    {
        while (!empty())
        {
            cout << arr[top--] << endl;
        }
    }
};

int main()
{
    Stack amit(4);
    amit.push(212);
    amit.push(123);
    amit.pop();
    amit.pop();
    amit.pop();
    amit.print();

    return 0;
}
