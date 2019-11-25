/*
LeetCode 498. Diagonal Traverse
medium
time:	72ms
space:	14.8mb
*/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        if(matrix.size()==0){
            return ret;
        }
        int s = 0;
        int x = 0;
        int y = 0;
        int status = 0;
        while(ret.size()<matrix.size()*matrix[0].size()){
            // cout<<x<<" "<<y<<endl;
            ret.push_back(matrix[x][y]);
            if(status==0){
                --x;
                ++y;
                if(x<0||y==matrix[0].size()){
                    status = 1;
                    if(y==matrix[0].size()){
                        --y;
                        x += 2;
                    }
                    else{
                        ++x;
                    }
                }
            }
            else{
                ++x;
                --y;
                if(y<0||x==matrix.size()){
                    status = 0;
                    if(x==matrix.size()){
                        --x;
                        y += 2;
                    }
                    else{
                        ++y;
                    }
                }
            }
        }
        return ret;
    }
};