#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool checkSubarraySum(vector<int> &nums, int k)
{
    if (nums.size() < 2)
        return false;

    unordered_map<int, int> m;
    m.insert({0, -2});
    int temp = 0;

    cout << m[0] << endl;
    for (int i = 0; i < nums.size(); i++)
    {

        temp = temp + nums[i];

        int rem = temp % k;
        cout << "Sum " << temp << " Remainder " << rem << " At " << i << endl;

        if (m.find(rem) != m.end())
        {

            int s = i - m[rem];
            cout << "Curr i " << i << " Same rem at index " << m[rem] << " Diff " << s << endl;
            if (s >= 2)
                return true;
        }
        else
        {
            m[rem] = i;
        }
    }
    return false;
}
using namespace std;
int main()
{
    vector<int> v = {1, 2, 3};
    cout << checkSubarraySum(v, 5) << endl;
    cout << -7 % 5;
}