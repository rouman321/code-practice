/*
LeetCode 1014. Best Sightseeing Pair
medium
time:	51.96%
space:	50%
*/
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int maxi = A[0];
        int ret = 0;
        for(int i = 1;i < A.size();i++){
            ret = max(ret,maxi+A[i]-i);
            maxi = max(maxi,A[i]+i);
        }
        return ret;
    }
};