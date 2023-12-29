#include <queue>
#include <iostream>
using namespace std;
int main()
{
    queue<int> q;
    q.push(2);
    q.push(12);
    q.push(34);
    q.push(8);

    cout << "Queue Size : " << q.size() << endl;
    cout << "Queue Front : " << q.front() << endl;
    cout << "Queue Back : " << q.back() << endl;
}