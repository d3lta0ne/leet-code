class Solution
{
public:
    double average(vector<int> &salary)
    {
        int minSalary = *min_element(salary.begin(), salary.end());
        int maxSalary = *max_element(salary.begin(), salary.end());
        double sum = accumulate(salary.begin(), salary.end(), 0);

        if (minSalary == maxSalary)
        {
            return 0;
        }

        return (sum - minSalary - maxSalary) / double(salary.size() - 2);
    }
};
