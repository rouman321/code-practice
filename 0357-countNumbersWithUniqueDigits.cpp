/*
LeetCode 357. Count Numbers with Unique Digits
medium
time:	51.08%
space:	83.33%
*/
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0){
            return 1;
        }
        vector<int> dp(n,0);
        dp[0] = 10;
        int cur = 9;
        int m = 9;
        for(int i = 1;i < n;i++){
            if(cur>0){
                m *= cur;
                dp[i] = dp[i-1]+m;
            }
            else{
                dp[i] = dp[i-1];
            }
            cur--;
        }
        return dp[n-1];
    }
};