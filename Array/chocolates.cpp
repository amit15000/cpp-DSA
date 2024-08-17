#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main()
{
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> chocolates(N);
    vector<int> boxes(M);

    // Input sizes of chocolates
    for (int i = 0; i < N; i++)
    {
        cin >> chocolates[i];
    }

    // Input sizes of boxes
    for (int i = 0; i < M; i++)
    {
        cin >> boxes[i];
    }

    // Sort chocolates and boxes
    sort(chocolates.begin(), chocolates.end());
    sort(boxes.begin(), boxes.end());

    long long totalCost = 0;
    int i = 0, j = 0;

    // Greedily pair chocolates with the smallest suitable boxes
    while (i < N && j < M)
    {
        if (chocolates[i] <= boxes[j])
        {
            totalCost = (totalCost + (long long)boxes[j] * K) % MOD;
            i++;
        }
        j++;
    }

    cout << totalCost << endl;

    return 0;
}
