/*
LeetCode 1018. Binary Prefix Divisible By 5
easy
time:	16ms
space:	10.6mb
*/
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> ret;
        int mod = 0;
        for(int i = 0;i < A.size();++i){
            mod = (mod*2+A[i])%5;
            ret.push_back(mod==0);
        }
        return ret;
    }
};