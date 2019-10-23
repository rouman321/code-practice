/*
LeetCode 718. Maximum Length of Repeated Subarray
medium
time:	43.52%
space:	50%
*/
class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        if(A.size()==0||B.size()==0){
            return 0;
        }
        vector<vector<int>> dp(A.size()+1,vector<int>(B.size()+1,0));
        int ret = 0;
        for(int i = 1;i <= A.size();i++){
            for(int j = 1;j <= B.size();j++){
                if(A[i-1]==B[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                    ret = max(dp[i][j],ret);
                }
            }
        }
        return ret;
    }
};