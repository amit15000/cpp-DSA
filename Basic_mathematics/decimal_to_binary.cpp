#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 7;
    int ans = 0, i = 0;
    while (n != 0)
    {
        int bit = n & 1;
        cout << "Current bit " << bit << endl;
        ans = (bit * pow(10, i)) + ans;
        cout << "Current ans " << ans << endl;
        n = n >> 1;
        i++;
    }
    cout << ans << endl;
    // Code not running locally for 7, 49 etc/
    // Run on online compier -> it's working
    return 0;
}