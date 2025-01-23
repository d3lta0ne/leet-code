#include <string>
class Solution
{
public:
    bool isAnagram(std::string s, std::string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }

        int counter[26]{};
        for (int i = 0; i < s.length(); i++)
        {
            counter[s.at(i) - 'a']++;
            counter[t.at(i) - 'a']--;
        }
        for (int count : counter)
        {
            if (count != 0)
            {
                return false;
            }
        }
        return true;
    }
};
