/*
LeetCode 1042. Flower Planting With No Adjacent
easy
time:	44.19%
space:	100%
*/
class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<int> ret(N,0);
        vector<unordered_set<int>> m(N,unordered_set<int>());
        for(int i = 0;i < paths.size();i++){
            m[paths[i][0]-1].insert(paths[i][1]-1);
            m[paths[i][1]-1].insert(paths[i][0]-1);
        }
        for(int i = 0;i < ret.size();i++){
            int tmp = 0;
            for(auto j: m[i]){
                if(ret[j]!=0){
                    tmp |= 1<<(ret[j]-1);
                }
            }
            for(int j = 0;j < 4;j++){
                if(!(tmp&1<<j)){
                    ret[i] = j+1;
                    break;
                }
            }
        }
        return ret;
    }
};