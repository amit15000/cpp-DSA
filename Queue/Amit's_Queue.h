#include <bits/stdc++.h>
using namespace std;
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
        if (rear == maxSize - 1)
        {
            std::cout << "Stack is full\n";
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
            std::cout << "Queue is empty\n";
        }

        if (front == rear)
        {
            // this was the only element remaining that u trying to pop
            arr[front] = -1;
            front = -1;
            rear = -1;
            return;
        }
        arr[front] = -1;
        front++;
    }

    int sizeOfQueue()
    {
        if (this->empty())
        {
            return 0;
        }
        return rear - front + 1;
    }
    int getFront()
    {
        if (this->empty())
        {
            cout << "Queue is empty";
            return -1;
        }
        return arr[front];
    }

    int getRear()
    {
        if (this->empty())
        {
            cout << "Queue is empty";
            return -1;
        }
        return arr[rear];
    }

    void printQueue()
    {
        if (this->empty())
        {
            cout << "Queue is empty";
            return;
        }
        for (int i = front; i <= rear; i++)
        {
            std::cout << arr[i] << " ";
        }
    }
};