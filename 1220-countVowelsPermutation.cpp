/*
LeetCode 1220. Count Vowels Permutation
hard
time:	41.15%
space:	100%
*/
class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<int>> dp(n,vector<int>(5,0));
        for(int i = 0;i < 5;i++){
            dp[0][i] = 1;
        }
        int mod = 1e9+7;
        for(int i = 1;i < n;i++){
            long tmp = 0;
            tmp = (long)dp[i-1][1]+(long)dp[i-1][2]+(long)dp[i-1][4];
            dp[i][0] = tmp%mod;
            tmp = (long)dp[i-1][0]+(long)dp[i-1][2];
            dp[i][1] = tmp%mod;
            tmp = (long)dp[i-1][1]+(long)dp[i-1][3];
            dp[i][2] = tmp%mod;
            dp[i][3] = dp[i-1][2];
            tmp = (long)dp[i-1][3]+(long)dp[i-1][2];
            dp[i][4] = tmp%mod;
        }
        int ret = 0;
        for(int i = 0;i < 5;i++){
            long tmp = ret;
            tmp = (tmp+dp[n-1][i])%mod;
            ret = tmp;
        }
        return ret;
    }
};