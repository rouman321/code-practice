/*
LeetCode 661. Image Smoother
easy
time:	24.28%
space:	83.33%
*/
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> ret(M.size(),vector<int>(M[0].size(),0));
        for(int i = 0;i < M.size();i++){
            for(int j = 0;j < M[i].size();j++){
                int num = 0;
                int sum = 0;
                for(int x = i-1;x <= i+1;x++){
                    for(int y = j-1;y <= j+1;y++){
                        if(x>=0&&x<M.size()&&y>=0&&y<M[x].size()){
                            sum += M[x][y];
                            num++;
                        }
                    }
                }
                ret[i][j] = sum/num;
            }
        }
        return ret;
    }
};