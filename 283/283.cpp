class Solution
{
public:
    void swap(int *x, int *y)
    {
        *y = *x ^ *y;
        *x = *x ^ *y;
        *y = *x ^ *y;
    }

    void moveZeroes(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return;

        int i;

        for (i = 1; i < nums.size(); i++)
        {
            if (nums.at(i) != 0 && nums.at(i - 1) == 0)
            {
                swap(&nums[i], &nums[i - 1]);
            }
        }

        return;
    }
};