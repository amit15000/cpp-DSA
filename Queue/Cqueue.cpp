#include "CircularQ.h"
using namespace std;
int main()
{
    CicularQueue cq(5);
    cq.push(12);
    cq.push(5);
    cq.push(-7);
    cq.push(8);
    cq.push(3);
    cq.printQueue();
    cq.pop();
    cq.pop();
    cq.pop();
    cq.pop();
    cq.push(12);
    cq.pop();
    cq.push(32);
    cq.pop();
    cq.pop();
    cq.pop();
    cq.push(32);
    cq.push(42);
    cq.push(52);
    cq.push(62);
    cq.push(72);
    cq.push(82);
    cq.pop();
    cq.printQueue();
}