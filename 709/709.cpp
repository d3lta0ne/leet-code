
class Solution
{
#define SIZE 26
public:
    string toLowerCase(string s)
    {
        map<char, char> alpha;
        string AZ = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string az = "abcdefghijklmnopqrstuvwxyz";

        int i;
        for (i = 0; i < SIZE; i++)
        {
            alpha.insert(pair<char, char>(AZ[i], az[i]));
        }

        // Convert each character in the string to lowercase if it's an uppercase letter
        for (int i = 0; i < s.size(); i++)
        {
            if (alpha.count(s[i]))
            {
                s[i] = alpha.at(s[i]);
            }
        }

        return s; // Return the modified string
    }
};