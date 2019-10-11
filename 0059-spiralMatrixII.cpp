/*
LeetCode 59. Spiral Matrix II
medium
time:	100%
space:	56.25%
*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n,vector<int>(n,0));
        int status = 0;
        int limit = n;
        int lb = 0;
        int cur = 1;
        int i = 0;
        int j = 0;
        while(cur<=n*n){
            ret[i][j] = cur;
            cur++;
            if(status==0){
                if(j+1>=limit){
                    i++;
                    status = 1;
                }
                else{
                    j++;
                }
            }
            else if(status==1){
                if(i+1>=limit){
                    j--;
                    status = 2;
                    limit--;
                }
                else{
                    i++;
                }
            }
            else if(status==2){
                if(j-1<lb){
                    i--;
                    status = 3;
                    lb++;
                }
                else{
                    j--;
                }
            }
            else{
                if(i-1<lb){
                    j++;
                    status = 0;
                }
                else{
                    i--;
                }
            }
        }
        return ret;
    }
};