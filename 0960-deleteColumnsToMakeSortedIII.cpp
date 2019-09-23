/*
LeetCode 960. Delete Columns to Make Sorted III
hard
time	78.21%
space	80%
*/
class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int len = A[0].size();
        vector<int> dp(len,1);
        for(int i = len-2;i >= 0;i--){
            for(int j = i+1;j < len;j++){
                bool flag = true;
                for(int x = 0;x < A.size();x++){
                    if(A[x][i]>A[x][j]){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    dp[i] = max(dp[i],1+dp[j]);
                }
            }
        }
        int ret = 0;
        for(int i = 0;i < dp.size();i++){
            ret = max(ret,dp[i]);
        }
        return len-ret;
    }
};