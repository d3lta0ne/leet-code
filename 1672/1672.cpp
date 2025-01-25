#include <vector>
#include <numeric>
#include <limits>

using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max_wealth = numeric_limits<int>::min();
        for (vector<int> customer : accounts) {
            int current_wealth = accumulate(customer.begin(), customer.end(), 0);
            max_wealth = max(max_wealth, current_wealth); 
        }

        return max_wealth;
    }
};