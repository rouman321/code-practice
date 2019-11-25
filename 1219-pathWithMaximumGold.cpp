/*
LeetCode 1219. Path with Maximum Gold
medium
time:	97.6%
space:	100%
*/
class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = 0;
        for(int i = 0;i < grid.size();i++){
            for(int j = 0;j < grid[i].size();j++){
                if(grid[i][j]!=0){
                    int tmp = 0;
                    int t = 0;
                    solve(grid,i,j,t,tmp);
                    m = max(m,tmp);
                }
            }
        }
        return m;
    }
    
    void solve(vector<vector<int>>& grid, int x, int y, int& cur, int& m){
        cur += grid[x][y];
        int tmp = grid[x][y];
        grid[x][y] = 0;
        m = max(cur,m);
        if(x>0&&grid[x-1][y]!=0){
            solve(grid,x-1,y,cur,m);
        }
        if(x<grid.size()-1&&grid[x+1][y]!=0){
            solve(grid,x+1,y,cur,m); 
        }
        if(y>0&&grid[x][y-1]!=0){
            solve(grid,x,y-1,cur,m);
        }
        if(y<grid[x].size()-1&&grid[x][y+1]!=0){
            solve(grid,x,y+1,cur,m);
        }
        grid[x][y] = tmp;
        cur -= tmp;
    }
};
