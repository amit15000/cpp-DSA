#include <iostream>
#include <vector>
using namespace std;

void getPermut(vector<vector<int>> &res, vector<int> arr, int l, int h)
{

    if (l == h)
    {
        res.push_back(arr);
    }

    for (int i = l; i <= h; i++)
    {
        swap(arr[i], arr[l]);
        getPermut(res, arr, l + 1, h);
    }
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr;

    for (int i = 1; i <= n; i++)
    {
        arr.push_back(i);
    }

    vector<vector<int>> res;

    getPermut(res, arr, 0, n - 1);

    for (auto vec : res)
    {
        for (auto t : vec)
        {
            cout << t << " ";
        }
        cout << endl;
    }
    return 0;
}