/*
LeetCode 96. Unique Binary Search Trees
medium
time:	100%
space:	52.27%
*/
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2;i <= n;i++){
            for(int j = 0;j < i;j++){
                dp[i] += dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
};