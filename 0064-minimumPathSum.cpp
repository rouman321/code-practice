/*
LeetCode 64. Minimum Path Sum
medium
time:	99.34%
space:	52.63%
*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size()==0){
            return 0;
        }
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),0));
        dp[0][0] = grid[0][0];
        for(int i = 0;i < grid.size();i++){
            for(int j = 0;j < grid[i].size();j++){
                if(i>0&&j>0){
                    dp[i][j] = min(dp[i-1][j],dp[i][j-1])+grid[i][j];
                }
                else if(i > 0){
                    dp[i][j] = dp[i-1][j]+grid[i][j];
                }
                else if(j > 0){
                    dp[i][j] = dp[i][j-1]+grid[i][j];
                }
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
};