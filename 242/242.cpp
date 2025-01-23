class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        // Step 1: Check if the strings have the same length
        if (s.size() != t.size())
        {
            return false;
        }

        char ch = 0;

        // Step 2: XOR all characters of both strings
        for (int i = 0; i < s.size(); i++)
        {
            ch ^= s[i]; // XOR character from string s
            ch ^= t[i]; // XOR character from string t
        }

        // Step 3: If the result is 0, the strings are anagrams
        return ch == 0;
    }
};
