/*
On a N * N grid, we place some 1 * 1 * 1 cubes that are axis-aligned with the x, y,
and z axes.

Each value v = grid[i][j] represents a tower of v cubes placed on top of grid cell
(i, j).

Now we view the projection of these cubes onto the xy, yz, and zx planes.

A projection is like a shadow, that maps our 3 dimensional figure to a 2
dimensional plane.

Here, we are viewing the "shadow" when looking at the cubes from the top, the front,
and the side.

Return the total area of all three projections.
*/
#include "../LCInput/numInput.h"

class Solution {
public:
    int projectionArea(vector<vector<int> >& grid) {
        int area = 0;
        if(grid.size() == 0)
        {
            return 0;
        }
        vector<int> maxCol(grid[0].size(),0);
        int maxRow = 0;
        for(int i = 0;i < grid.size();i++)
        {
            maxRow = 0;
            for(int j = 0;j < grid[i].size();j++)
            {
                if(grid[i][j] != 0)
                {
                    area++;
                    maxRow = max(maxRow,grid[i][j]);
                    maxCol[j] = max(maxCol[j],grid[i][j]);
                }
            }
            area += maxRow;
        }
        for(int i = 0;i < maxCol.size();i++)
        {
            area += maxCol[i];
        }
        return area;
    }
};

int main()
{
    vector<vector<int> > grid = oneLineVectorVectorInput("in.txt");
    Solution s;
    cout<<s.projectionArea(grid)<<endl;
    return 0;
}
