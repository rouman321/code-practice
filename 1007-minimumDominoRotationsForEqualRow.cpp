/*
LeetCode 1007. Minimum Domino Rotations For Equal Row
medium
time:	27.19%
space:	83.33%
*/
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        vector<int> mark(6,0);
        for(int i = 0;i < A.size();i++){
            mark[A[i]-1]++;
        }
        for(int i = 0;i < B.size();i++){
            mark[B[i]-1]++;
        }
        int target = 0;
        for(int i = 0;i < 6;i++){
            if(mark[i]>=A.size()){
                target = i+1;
                break;
            }
        }
        int cnt = 0;
        int len = A.size();
        for(int i = 0;i < A.size();i++){
            if(A[i]!=target){
                if(B[i]!=target){
                    return -1;
                }
                cnt++;
            }
            else if(A[i]==B[i]){
                len--;
            }
        }
        if(cnt*2>len){
            return len-cnt;
        }
        return cnt;
    }
};