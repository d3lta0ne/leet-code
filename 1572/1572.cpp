#include <vector>

using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;
        for(int i = 0; i < n; i++){
            //primary d
            sum += mat[i][i];
            
            //secondary d
            sum += mat[i][n-1-i];                
        }

        // remove duplicate count on odds
        if(n%2!=0){
            sum -= mat[n/2][n/2];
        }

        return sum;
    }
};