#include <iostream>
#include <queue>
using namespace std;
void insertInPriorityQueue(priority_queue<int, vector<int>, greater<int>> &q)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        q.push(data);
        cin >> data;
    }
}
int main()
{

    // Min heap
    priority_queue<int, vector<int>, greater<int>> q;

    // maxheap
    priority_queue<int> maxHeap;
    insertInPriorityQueue(q);

    cout << q.top();

    cout << q.top();
}