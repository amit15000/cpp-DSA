int q = []
{
    char ch;
    std::vector<std::string> nums;
    nums.clear();
    ofstream ans("user.out");
    while (std::cin >> ch)
    {
        string s = "";
        nums.clear();
        do
        {
            ch = getchar();
            s += ch;
        } while (ch != ']');
        ans << "[";

        if (s.size() != 1)
        {

            int n = 0;

            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == ',' || i == s.size() - 1)
                {
                    nums.push_back(s.substr(n, i - n));
                    n = i + 1;
                }
            }

            for (int p = nums.size() - 1; p >= 0; p--)
            {
                ans << nums[p];
                if (p != 0)
                    ans << ",";
            }
        }
        ans << "]" << endl;
    }
    exit(0);
    return 0;
}();
class Solution
{
public:
    ListNode *rl(ListNode *&prev, ListNode *&curr)
    {
        if (curr == NULL)
        {
            return prev;
        }
        ListNode *right = curr->next;
        curr->next = prev;
        return rl(curr, right);
    }
    ListNode *reverseList(ListNode *head)
    {
        return 0;
    }
};