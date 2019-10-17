/*
LeetCode 554. Brick Wall
medium
time:	12.71%
space:	16.67%
*/
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int height = wall.size();
        unordered_map<int,vector<int>> m;
        for(int i = 0;i < height;i++){
            int wid = 0;
            for(int j = 0;j < wall[i].size()-1;j++){
                wid += wall[i][j];
                if(m.find(wid)==m.end()){
                    m[wid] = vector<int>();
                }
                m[wid].push_back(i);
            }
        }
        if(m.size()==0){
            return height;
        }
        int ret = INT_MAX;
        for(auto i: m){
            ret = min(ret,(int)(height-i.second.size())); 
        }
        return ret;
    }
};