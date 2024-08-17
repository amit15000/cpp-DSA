#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> chocolates(N);
    vector<int> boxes(M);

    for (int i = 0; i < N; i++)
    {
        cin >> chocolates[i];
    }
    for (int j = 0; j < M; j++)
    {
        cin >> boxes[j];
    }

    sort(chocolates.begin(), chocolates.end());
    sort(boxes.begin(), boxes.end());

    long long totalCost = 0;
    const int MOD = 1e9 + 7;

    int i = 0, j = 0;
    while (i < N)
    {
        while (j < M && chocolates[i] > boxes[j])
        {
            j++;
        }
        if (j < M)
        {
            totalCost += (long long)K * boxes[j] % MOD;
            totalCost %= MOD;
            j++;
        }
        i++;
    }

    cout << totalCost << endl;
    return 0;
}