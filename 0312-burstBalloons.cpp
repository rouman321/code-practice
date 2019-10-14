/*
LeetCode 312. Burst Balloons
hard
time:	5.16%
space:	5%
*/
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size(),-1));
        return solve(nums,0,nums.size()-1,dp);
    }
    
    int solve(vector<int> nums, int start, int end, vector<vector<int>>& dp){
        if(dp[start][end]!=-1){
            return dp[start][end];
        }
        int l = start>0?nums[start-1]:1;
        int r = end<nums.size()-1?nums[end+1]:1;
        if(start==end){
            dp[start][end] = l*nums[start]*r;
            return dp[start][end];
        }
        int m = 0;
        for(int i = start;i <= end;i++){
            int left = i==start?0:solve(nums,start,i-1,dp);
            int right = i==end?0:solve(nums,i+1,end,dp);
            m = max(m,left+l*nums[i]*r+right);
        }
        dp[start][end] = m;
        return m;
    }
};