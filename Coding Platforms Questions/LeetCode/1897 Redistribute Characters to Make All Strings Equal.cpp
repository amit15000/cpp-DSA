class Solution
{
public:
    bool makeEqual(vector<string> &words)
    {
        if (words.size() == 1)
        {
            return true;
        }

        int totalChars = 0;

        for (std::string s : words)
        {
            totalChars += s.length();
        }

        if (totalChars % words.size() != 0)
        {
            return false;
        }

        int myMap[26] = {0};

        for (string s : words)
        {
            for (char c : s)
            {
                myMap[c - 'a']++;
            }
        }

        for (int i : myMap)
        {
            if (i % words.size() != 0)
            {
                return false;
            }
        }

        return true;
    }
};