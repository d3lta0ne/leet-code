#include <vector>

class Solution
{
public:
    void moveZeroes(std::vector<int> &nums)
    {
        int r, w;
        r = 0;
        w = 0;
        for (r = 0; r < nums.size(); r++)
        {
            if (nums[r] != 0)
            {
                nums[w++] = nums[r];
            }
        }

        while (w < nums.size())
        {
            nums[w++] = 0;
        }
    }
};