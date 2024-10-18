#include <iostream>
#include <queue>

using namespace std;
int main()
{
    int num;
    cin >> num;
    priority_queue<int> pq;
    while (num != 0)
    {
        int d = num % 10;
        pq.push(d);
        num /= 10;
    }

    int res = 0;

    while (!pq.empty())
    {
        res = res * 10 + pq.top();
        pq.pop();
    }
    cout << res << endl;
    return 0;
}