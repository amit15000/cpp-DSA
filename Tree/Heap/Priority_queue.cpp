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

    // Push --- create object then insert
    q.push(12);

    // Difference when queue is of user defined data sturcture ...==>constructor call to that ds  then insertion in queue.==> q.push(MyObject(12))
    // q.push(MyObject(12)

    // Emplace--- > directly insert
    q.emplace(34);
    // q.push(MyObject(12) ===> no need to write like this ===>>>>>>>>>> direclty write  q.emplace(12);

    cout << q.top();

    cout << q.top();
}