#include <iostream>

class Stack
{
private:
    int *arr = NULL;
    int size;
    int TOP;

public:
    // constructor
    Stack(int maxSize)
    {
        arr = new int[maxSize];
        size = maxSize;
        TOP = -1;
    }

    // insert
    void push(int val)
    {
        // check if stack is full
        if (TOP == size - 1)
        {
            printf("Stack is Full");
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
            printf("Stack is Empty");
            return;
        }

        TOP--;
    }
    void printStack()
    {
        for (int i = 0; i <= TOP; i++)
        {
            std::cout << arr[i] << " ";
        }
    }
};
