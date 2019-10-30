/*
LeetCode 486. Predict the Winner
medium
time:	4ms
space:	8.4mb
*/
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1,vector<int>(nums.size(),0));
        for(int i = nums.size();i >= 0;--i){
            for(int j = i+1;j < nums.size();++j){
                dp[i][j] = max(nums[i]-dp[i+1][j],nums[j]-dp[i][j-1]);
            }
        }
        return dp[0][nums.size()-1]>=0;
    }
};