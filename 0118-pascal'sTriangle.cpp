/*
LeetCode 118. Pascal's Triangle
easy
time:	61.14%
space:	100%
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        int column = 0;
        for(int i = 0;i < numRows;i++){
            column = i+1;
            ret.push_back(vector<int>());
            for(int j = 0;j < column;j++){
                if(j==0||j==column-1){
                    ret[i].push_back(1);
                }
                else{
                    ret[i].push_back(ret[i-1][j-1]+ret[i-1][j]);
                }
            }
        }
        return ret;
    }
};