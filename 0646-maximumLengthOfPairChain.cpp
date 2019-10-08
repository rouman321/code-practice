/*
LeetCode 646. Maximum Length of Pair Chain
medium
time:	35.03%
space:	100%
*/
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        vector<int> dp(pairs.size(),1);
        for(int i = 0;i < pairs.size();i++){
            for(int j = 0;j < i;j++){
                if(pairs[i][0]>pairs[j][1]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }
        int ret = 0;
        for(int i = 0;i < dp.size();i++){
            ret = max(ret,dp[i]);
            // cout<<dp[i]<<" ";
        }
        // cout<<endl;
        return ret;
    }
};