/*
LeetCode 1027. Longest Arithmetic Sequence
medium
time:	76.72%
space:	86.67%
*/
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        vector<unordered_map<int,int>> dp(A.size(),unordered_map<int,int>());
        for(int i = 1;i < A.size();i++){
            for(int j = 0;j < i;j++){
                int d = A[i]-A[j];
                if(dp[j].find(d)==dp[j].end()){
                    dp[i][d] = 2;
                }
                else{
                    dp[i][d] = dp[j][d]+1;
                }
            }
        }
        int ret = 0;
        for(int i = 0;i < A.size();i++){
            for(auto j:dp[i]){
                ret = max(ret,j.second);
            }
        }
        return ret;
    }
};