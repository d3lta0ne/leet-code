#include <vector>

class Solution
{
public:
    int findMaxConsecutiveOnes(std::vector<int> &nums)
    {
        int max = 0;
        int ctr = 0;
        for (int n : nums)
        {
            if (n == 1)
            {
                ctr++;
                if (ctr > max)
                    max = ctr;
            }
            else
            {
                ctr = 0;
            }
        }
        return max;
    }
};