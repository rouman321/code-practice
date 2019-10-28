/*
LeetCode 1053. Previous Permutation With One Swap
medium
time:	112ms
space:	12.7mb
*/
class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int i = A.size()-2;
        while(i>=0&&A[i]<=A[i+1]){
            --i;
        }
        if(i!=-1){
            int l = i;
            int m = 0;
            int r = 0;
            i = l+1;
            while(i<A.size()&&A[i]<A[l]){
                if(A[i]>m){
                    m = A[i];
                    r = i;
                }
                ++i;
            }
            swap(A[l],A[r]);
        }
        return A;
    }
};