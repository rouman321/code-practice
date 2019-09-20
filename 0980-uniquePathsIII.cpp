/*
On a 2-dimensional grid, there are 4 types of squares:

1 represents the starting square.  There is exactly one starting square.
2 represents the ending square.  There is exactly one ending square.
0 represents empty squares we can walk over.
-1 represents obstacles that we cannot walk over.

Return the number of 4-directional walks from the starting square to the ending
square, that walk over every non-obstacle square exactly once.
*/
#include "../LCInput/numInput.h"

class Solution {
public:
    void dfs(vector<vector<int> >& grid,int x,int y,int n)
    {
        if(n == 1&&grid[x][y] == 2)
        {
            cnt++;
        }
        else
        {
            int tmp = grid[x][y];
            grid[x][y] = -1;
            if(x+1 < grid.size()&&grid[x+1][y] != -1)
            {
                dfs(grid,x+1,y,n-1);
            }
            if(x-1 >= 0&&grid[x-1][y] != -1)
            {
                dfs(grid,x-1,y,n-1);
            }
            if(y+1 < grid[x].size()&&grid[x][y+1] != -1)
            {
                dfs(grid,x,y+1,n-1);
            }
            if(y-1 >= 0&&grid[x][y-1] != -1)
            {
                dfs(grid,x,y-1,n-1);
            }
            grid[x][y] = tmp;
        }
    }
    int uniquePathsIII(vector<vector<int> >& grid) {
        if(grid.size() == 0)
        {
            return 0;
        }
        cnt = 0;
        int len = 0;
        int x,y;
        for(int i = 0;i < grid.size();i++)
        {
            for(int j = 0;j < grid[i].size();j++)
            {
                if(grid[i][j] != -1)
                {
                    len++;
                }
                if(grid[i][j] == 1)
                {
                    x = i;
                    y = j;
                }
            }
        }
        dfs(grid,x,y,len);
        return cnt;
    }
private:
    int cnt;
};

int main()
{
    vector<vector<int> > grid = sigendOneLineVectorVectorInput("in.txt");
    Solution s;
    cout<<s.uniquePathsIII(grid)<<endl;
    return 0;
}
