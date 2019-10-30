/*
LeetCode 974. Subarray Sums Divisible by K
medium
time:	68ms
space:	12.2mb
*/
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int ret = 0;
        vector<int> cnt(K,0);
        int sum = 0;
        for(int i = 0;i < A.size();++i){
            sum += A[i];
            while(sum<0){
                sum += K;
            }
            sum %= K;
            ++cnt[sum];
        }
        ++cnt[0];
        for(int i = 0;i < K;++i){
            ret += cnt[i]*(cnt[i]-1)/2;
        }
        return ret;
    }
};