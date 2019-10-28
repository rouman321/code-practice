/*
LeetCode 650. 2 Keys Keyboard
medium
time:	100%
space:	25%
*/
class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[1] = 0;
        for(int i = 1;i <= n;i++){
            int pos = 2;
            int step = dp[i]+1;
            while(i*pos<=n){
                step++;
                dp[i*pos] = min(dp[i*pos],step);
                pos++;
            }
        }
        return dp[n];
    }
};