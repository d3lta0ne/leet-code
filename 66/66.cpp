/**
 * /***
 * 66. Plus One
 * Author: D3lta0ne
 * Published: 1/23/25
 */
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();

        for (int i = n - 1; i >= 0; --i)
        {
            if (digits[i] == 9)
            {
                digits[i] = 0;
            }
            else
            {
                digits[i]++;
                return digits;
            }
        }

        // We're here because all the digits are nines
        digits.insert(digits.begin(), 1);
        return digits;
    }
};