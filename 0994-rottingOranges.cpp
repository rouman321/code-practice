/*
LeetCode 994. Rotting Oranges
easy
time:	4ms
space:	9.2mb
*/
typedef struct Point{
    int x;
    int y;
}point;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<point,int>> q;
        for(int i = 0;i < grid.size();++i){
            for(int j = 0;j < grid[i].size();++j){
                if(grid[i][j]==2){
                    point tmp;
                    tmp.x = i;
                    tmp.y = j;
                    q.push(make_pair(tmp,0));
                }
            }
        }
        int ret = 0;
        while(!q.empty()){
            point cur = q.front().first;
            int step = q.front().second;
            q.pop();
            ret = max(step,ret);
            if(cur.x>0&&grid[cur.x-1][cur.y]==1){
                grid[cur.x-1][cur.y] = 2;
                point next;
                next.x = cur.x-1;
                next.y = cur.y;
                q.push(make_pair(next,step+1));
            }
            if(cur.y>0&&grid[cur.x][cur.y-1]==1){
                grid[cur.x][cur.y-1] = 2;
                point next;
                next.x = cur.x;
                next.y = cur.y-1;
                q.push(make_pair(next,step+1));
            }
            if(cur.x<grid.size()-1&&grid[cur.x+1][cur.y]==1){
                grid[cur.x+1][cur.y] = 2;
                point next;
                next.x = cur.x+1;
                next.y = cur.y;
                q.push(make_pair(next,step+1));
            }
            if(cur.y<grid[cur.x].size()-1&&grid[cur.x][cur.y+1]==1){
                grid[cur.x][cur.y+1] = 2;
                point next;
                next.x = cur.x;
                next.y = cur.y+1;
                q.push(make_pair(next,step+1));
            }
        }
        for(int i = 0;i < grid.size();++i){
            for(int j = 0;j < grid[i].size();++j){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return ret;
    }
};