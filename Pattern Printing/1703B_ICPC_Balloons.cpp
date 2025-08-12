#include <iostream>
using namespace std;

int kthNumber(int k)
{
    int cnt = 0;
    for (int num = 1; num <= 50; num++)
    {
        if (num % 10 == 3 || num % 3 == 0)
        {
            continue;
        }
        cnt++;

        if (cnt == k)
        {
            return num;
        }
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int k;
        cin >> k;

        cout << kthNumber(k) << endl;
    }
    return 0;
}