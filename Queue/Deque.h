#include <iostream>
class Deque
{
private:
    int *arr = nullptr;
    int front;
    int rear;
    int maxSize;

public:
    Deque(int val)
    {
        arr = new int[val];
        maxSize = val;
        front = -1;
        rear = -1;
    }

    void push(int val)
    {
    }
};
