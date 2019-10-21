/*
LeetCode 343. Integer Break
medium
time:	100%
space:	60%
*/
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,0);
        dp[1] = 1;
        for(int i = 2;i <= n;i++){
            dp[i] = i-1;
            for(int j = 2;j < i;j++){
                dp[i] = max(dp[i],dp[j]*dp[i-j]);
            }
            if(i!=n){
                dp[i] = max(dp[i],i);
            }
        }
        return dp[n];
    }
};