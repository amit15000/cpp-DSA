#include "Amit's_Queue.h"
#include <iostream>
using namespace std;
int main()
{
    Queue q(5);

    q.push(12);
    q.push(4);
    q.push(-7);
    q.push(9);
    q.push(-7);
    // // q.push(2);
    cout << q.sizeOfQueue() << endl;
    // q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();

    q.printQueue();
}