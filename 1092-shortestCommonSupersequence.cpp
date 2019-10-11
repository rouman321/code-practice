/*
LeetCode 1092. Shortest Common Supersequence
hard
time:	97.92%
space:	100%
*/
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int>> dp(str1.size()+1,vector<int>(str2.size()+1,0));
        dp[1][0] = 1;
        dp[0][1] = 1;
        for(int i = 0;i < str1.size();i++){
            dp[i+1][0] = dp[i][0]+1;
        }
        for(int i = 0;i < str2.size();i++){
            dp[0][i+1] = dp[0][i]+1;
        }
        for(int i = 0;i < str1.size();i++){
            for(int j = 0;j < str2.size();j++){
                if(str1[i]==str2[j]){
                    dp[i+1][j+1] = dp[i][j]+1;
                }
                else{
                    if(dp[i+1][j]>dp[i][j+1]){
                        dp[i+1][j+1] = dp[i][j+1]+1;
                    }
                    else{
                        dp[i+1][j+1] = dp[i+1][j]+1;
                    }
                }
            }
        }
        string ret(dp[str1.size()][str2.size()],'a');
        int l = str1.size();
        int r = str2.size();
        while(l>0&&r>0){
            if(str1[l-1]!=str2[r-1]){
                if(dp[l][r]==dp[l-1][r]+1){
                    ret[dp[l-1][r]] = str1[l-1];
                    l--;
                }
                else{
                    ret[dp[l][r-1]] = str2[r-1];
                    r--;
                }
            }
            else{
                ret[dp[l-1][r-1]] = str1[l-1];
                l--;
                r--;
            }
        }
        while(l>0){
            ret[l-1] = str1[l-1];
            l--;
        }
        while(r>0){
            ret[r-1] = str2[r-1];
            r--;
        }
        return ret;
    }
};