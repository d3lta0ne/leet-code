#include <vector>
class Solution
{
public:
    void moveZeroes(std::vector<int> &nums)
    {
        for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++)
        {
            if (nums[cur] != 0)
            {
                std::swap(nums[lastNonZeroFoundAt++], nums[cur]);
            }
        }
    }
};