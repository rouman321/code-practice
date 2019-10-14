/*
LeetCode 1155. Number of Dice Rolls With Target Sum
medium
time:	54.89%
space:	100%
*/
class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<int>> dp(d,vector<int>(target+1,0));
        int mod = 1e9+7;
        for(int i = 1;i <= f;i++){
            if(i > target){
                break;
            }
            dp[d-1][i] = 1;
        }
        for(int i = d-2;i >= 0;i--){
            for(int j = 1;j <= target;j++){
                for(int k = 1;k <= f;k++){
                    // cout<<i<<" "<<j<<" "<<k<<endl;
                    if(j-k<=0){
                        break;
                    }
                    long tmp = dp[i][j];
                    tmp += dp[i+1][j-k];
                    dp[i][j] = tmp%mod;
                }
            }
        }
        return dp[0][target];
    }
};