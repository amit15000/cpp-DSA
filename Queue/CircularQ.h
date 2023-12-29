#include <bits/stdc++.h>
using namespace std;
class CicularQueue
{
private:
    int *arr = nullptr;
    int maxSize;
    int front;
    int rear;

public:
    // constructor
    CicularQueue(int val)
    {
        arr = new int[val];
        maxSize = val;
        front = -1;
        rear = -1;
    }

    void push(int val)
    {
        // check if stack is full
        if (front == 0 && rear == maxSize - 1 || rear == front - 1)
        {
            cout << "Stack is full\n";
            return;
        }
        if (front == -1 && rear == -1)
        {
            front = 0;
            rear = 0;
            arr[front] = val;
            return;
        }
        // circular nature
        if (rear == maxSize - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = val;
            return;
        }
        // normal case
        rear++;
        arr[rear] = val;
    }
    void pop()
    {
        // chekc if stack is empty
        if (front == -1 && rear == -1)
        {
            cout << "Stack is empty\n";
            return;
        }
        if (front == rear)
        {
            // this is the last element
            arr[front] = 1;
            front = -1;
            rear = -1;
            return;
        }
        if (front == maxSize - 1)
        {
            arr[front] = -1;
            front = 0;
            return;
        }

        // normal case
        arr[front] = -1;
        front++;
    }

    void printQueue()
    {
        if (front == -1 && rear == -1)
        {
            cout << "Queue is isEmpty";
            return;
        }
        for (int i = 0; i < maxSize; i++)
        {
            std::cout << arr[i] << " ";
        }
        cout << "\n";
    }
};