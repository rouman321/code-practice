/*
LeetCode 903. Valid Permutations for DI Sequence
hard
time:	40ms
space:	10mb
*/
class Solution {
public:
    int numPermsDISequence(string S) {
        int mod = 1e9+7;
        int n = S.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i = 0;i <= n;++i){
            dp[0][i] = 1;
        }
        for(int i = 1;i <= n;++i){
            for(int j = 0;j <= i;++j){
                if(S[i-1]=='D'){
                    for(int m = j;m < i;++m){
                        dp[i][j] = ((long)dp[i][j]+dp[i-1][m])%mod;
                    }
                }
                else{
                    for(int m = 0; m < j;++m){
                        dp[i][j] = ((long)dp[i][j]+dp[i-1][m])%mod;
                    }
                }
            }
        }
        int ret = 0;
        for(int i = 0;i <= n;++i){
            ret = ((long)dp[n][i]+ret)%mod;
        }
        return ret;
    }
};