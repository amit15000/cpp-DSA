#include <vector>
#include <iterator>
#include <iostream>
using namespace std;

int calculatePossibelPair(vector<int> &nums, vector<int>::iterator &v, int res)
{
    if (v == nums.end())
    {
        return res;
    }

    for (int)
}

int main()
{
    int a;
    vector<int> nums;
    while (cin >> a)
    {
        nums.push_back(a);
    }

    int maxWeight;
    cin >> maxWeight;

    int res;
    vector<int>::iterator v;
    calculatePossibelPair(nums, v, res);
}