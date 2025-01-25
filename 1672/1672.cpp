#include <vector>
#include <numeric>
#include <limits>

using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int max_wealth = -1;
        for (auto customer : accounts){
            int cur_wealth = 0;
            for(auto bank : customer){
                cur_wealth+=bank;
            }

            if(cur_wealth > max_wealth) max_wealth=cur_wealth;
        }

        return max_wealth;
    }
};