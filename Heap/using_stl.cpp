#include <iostream>
#include <queue>
using namespace std;
int main()
{
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(4);
    minHeap.push(14);
    minHeap.push(3);
    minHeap.push(-7);
    minHeap.push(10);

    cout << "Top : " << minHeap.top() << endl;
    minHeap.pop();
    cout << "Top : " << minHeap.top() << endl;

    // priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int> maxHeap;
    // Default priotiy queue ===> maxHeap

    maxHeap.push(4);
    maxHeap.push(14);
    maxHeap.push(3);
    maxHeap.push(-7);
    maxHeap.push(10);

    cout << "Top : " << maxHeap.top() << endl;
    maxHeap.pop();
    cout << "Top : " << maxHeap.top() << endl;
}