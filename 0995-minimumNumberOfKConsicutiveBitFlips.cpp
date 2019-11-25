/*
LeetCode 995. Minimum Number of K Consecutive Bit Flips
hard
time:	88ms
space:	18.8mb
*/
class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        int cnt = 0;
        int flip = 1;
        vector<int> sign(A.size(),0);
        for(int i = 0;i < A.size();++i){
            flip ^= sign[i];
            if(flip!=A[i]){
                ++cnt;
                if(i+K>A.size()){
                    return -1;
                }
                if(i+K<A.size()){
                    sign[i+K] ^= 1;
                }
                flip ^= 1;
            }
        }
        return cnt;
    }
};