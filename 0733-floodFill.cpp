/*
LeetCode 733. Flood Fill
easy
time:	6.81%
space:	77.78%
*/
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(newColor==image[sr][sc]){
            return image;
        }
        dfs(image,sr,sc,newColor);
        return image;
    }
    
    void dfs(vector<vector<int>>& image, int x, int y, int n){
        int o = image[x][y];
        image[x][y] = n;
        if(x>0&&image[x-1][y]==o){
            dfs(image,x-1,y,n);
        }
        if(x<image.size()-1&&image[x+1][y]==o){
            dfs(image,x+1,y,n);
        }
        if(y>0&&image[x][y-1]==o){
            dfs(image,x,y-1,n);
        }
        if(y<image[x].size()-1&&image[x][y+1]==o){
            dfs(image,x,y+1,n);
        }
    }
};