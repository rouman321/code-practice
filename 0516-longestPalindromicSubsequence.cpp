/*
LeetCode 516. Longest Palindromic Subsequence
medium
time:	8.26%
space:	100%
*/
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(),vector<int>(s.size(),1));
        for(int i = 1;i<s.size();i++){
            for(int j = 0;j < i;j++){
                dp[i][j] = 0;
            }
        }
        for(int i = s.size()-2;i >= 0;i--){
            for(int j = i+1;j < s.size();j++){
                if(s[i]==s[j]){
                    dp[i][j] = max(dp[i][j],dp[i+1][j-1]+2);
                }
                else{
                    dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                }
            }
        }
        return dp[0][s.size()-1];
    }
};