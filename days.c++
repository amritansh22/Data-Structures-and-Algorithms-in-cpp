class Solution
{
public:
    string longestPrefix(string s)
    {
        // approach1
        int n = s.length();
        string prefix = s.substr(0, n - 1);
        string suffix = s.substr(1, n - 1);
        while (prefix.length())
        {
            if (prefix == suffix)
            {
                return prefix;
            }
            else
            {
                prefix.pop_back();
                suffix = suffix.substr(1, suffix.size() - 1);
            }
        }
        return "";