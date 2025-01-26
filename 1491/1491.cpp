#include <limits>
#include <vector>

using namespace std;

class Solution
{
public:
    double average(vector<int> &salary)
    {
        int min = numeric_limits<int>::max();
        int max = numeric_limits<int>::min();
        double count = 0.0;

        for (int employee : salary)
        {
            count += employee;
            if (employee > max)
                max = employee;
            if (employee < min)
                min = employee;
        }

        // what if the min and the max salary at the same?
        if (min == max)
        {
            count -= min;
            return count / (salary.size() - 1);
        }
        else
        {
            count -= (min + max);
            return count / (salary.size() - 2);
        }
    }
};