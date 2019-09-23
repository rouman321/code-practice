/*
LeetCode 1035. Uncrossed Lines
medium
time	89.72%
space	68.18%
*/
class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        if(A.size()==0||B.size()==0){
            return 0;
        }
        int sizeA = A.size();
        int sizeB = B.size();
        vector<vector<int>> dp(sizeA+1,vector<int> (sizeB+1,0));
        for(int i = 1;i <= sizeA;i++){
            for(int j = 1;j <= sizeB;j++){
                if(A[i-1]==B[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[sizeA][sizeB];
    }
};