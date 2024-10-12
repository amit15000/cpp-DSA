#include <iostream>
#include <string>
#include <map>
class Solution
{
public:
    int findTheLongestSubstring(string s)
    {
        int n = s.size();
        int res = 0;
        for (int l = 2; l < n; l++)
        {
            map<char, int> mp;
            for (int i = 0; i < n - 2; i++)
            {
                int j = i;

                while (j < i + l)
                {
                    char c = s[j];
                    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                    {
                        mp[c]++;
                    }
                }
                bool v = 1;
                for (auto it : mp)
                {
                    if (it.second & 1 == 1)
                    {
                        v = 0;
                    }
                }

                if (v)
                {
                    res = max(res, l);
                }
            }
        }

        return res;
    }
};
int main()
{
    Solution s;
    cout << s.findTheLongestSubstring("eleetminicoworoep") << endl;
}