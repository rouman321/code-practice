/*
LeetCode 667. Beautiful Arrangement II
medium
time:   57.11%
space:  100%
*/

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ret(n,0);
        int inc = 1;
        ret[0] = 1;
        for(int i = 1;i < n;i++){
            if(k==0){
                ret[i] = i+1;
            }
            else{
                ret[i] = ret[i-1]+inc*k;
                k--;
                inc *= -1;
            }
        }
        return ret;
    }
};