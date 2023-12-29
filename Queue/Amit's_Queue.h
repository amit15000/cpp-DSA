#include <iostream>
class Queue
{
private:
    int *arr = nullptr;
    int maxSize;
    int front;
    int rear;

public:
    // constructor
    Queue(int val)
    {
        arr = new int[val];
        maxSize = val;
        front = -1;
        rear = -1;
    }

    bool empty()
    {
        if (front == -1 && rear == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void push(int val)
    {
        // check if queue is full
        if (rear == maxSize)
        {
            std::cout << "Stack is full";
            return;
        }

        // check if this is first element to be pushed
        if (this->empty())
        {
            front++;
        }

        rear++;
        arr[rear] = val;
    }
    void pop()
    {
        // check if queue is empty
        if (this->empty())
        {
            std::cout << "Queue is empty";
        }

        if (front == rear)
        {
            // this was the only element remaining that u trying to pop
            front = -1;
            rear = -1;
            return;
        }
        front++;
    }

    int sizeOfQueue()
    {
        return rear - front + 1;
    }
};