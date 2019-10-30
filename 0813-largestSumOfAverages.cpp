/*
LeetCode 813. Largest Sum of Averages
medium
time:	12ms
space:	8.7mb
*/
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        vector<int> pre;
        pre.push_back(0);
        for(int i = 0;i < A.size();++i){
            pre.push_back(pre[i]+A[i]);
        }
        vector<double> dp(A.size(),0);
        int n = A.size();
        for(int i = 0;i < n;++i){
            dp[i] = (double)(pre[n]-pre[i])/(n-i);
        }
        for(int k = 0;k < K-1;++k){
            for(int i = 0;i < n;++i){
                for(int j = i+1;j < n;++j){
                    double tmp = (double)(pre[j]-pre[i])/(j-i);
                    dp[i] = max(dp[i],tmp+dp[j]);
                }
            }
        }
        return dp[0];
    }
};