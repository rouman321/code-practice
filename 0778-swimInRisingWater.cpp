/*
LeetCode 778. Swim in Rising Water
hard
time:	22.03%
space:	5.00%
*/
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int l = max(grid[row-1][col-1],grid[0][0]);
        int r = row*col-1;
        vector<vector<bool>> check(row,vector<bool>(col,false));
        check[0][0] = true;
        while(l<r){
            int mid = (l+r)/2;
            // cout<<mid<<endl;
            if(dij(grid,check,mid)){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
    
    bool dij(vector<vector<int>> grid, vector<vector<bool>> check, int limit){
        int row = grid.size();
        int col = grid[0].size();
        int cnt = 0;
        while(cnt <= row*col){
            int change = 0;
            for(int i = 0;i < row;i++){
                for(int j = 0;j < col;j++){
                    if(!check[i][j]&&grid[i][j]<=limit){
                        if((i>0&&check[i-1][j])||(i<row-1&&check[i+1][j])||(j>0&&check[i][j-1])||(j<col-1&&check[i][j+1])){
                            check[i][j] = true;
                            change++;
                        }
                    }
                }
            }
            if(change==0){
                break;
            }
            cnt++;
        }
        return check[row-1][col-1];
    }
};