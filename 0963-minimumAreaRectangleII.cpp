/*
LeetCode 963. Minimum Area Rectangle II
medium
time:	160ms
space:	58.3mb
*/
class Solution {
public:
    bool is_rec(pair<vector<int>,vector<int>>& ac, pair<vector<int>,vector<int>>& bd){
        return (ac.first[0]-bd.first[0])*(ac.first[0]-bd.second[0])==-1*(ac.first[1]-bd.first[1])*(ac.first[1]-bd.second[1]);
    }
    vector<int> cal(vector<int>& a, vector<int>& b){
        return {a[0]+b[0],a[1]+b[1]};
    }
    double area(pair<vector<int>,vector<int>>& ac, pair<vector<int>,vector<int>>& bd){
        return sqrt(abs(ac.first[0]-bd.first[0])*abs(ac.first[0]-bd.first[0])+abs(ac.first[1]-bd.first[1])*abs(ac.first[1]-bd.first[1]))*sqrt(abs(ac.first[0]-bd.second[0])*abs(ac.first[0]-bd.second[0])+abs(ac.first[1]-bd.second[1])*abs(ac.first[1]-bd.second[1]));
    }
    double minAreaFreeRect(vector<vector<int>>& points) {
        double ret = INT_MAX;
        unordered_map<int,unordered_map<int,vector<pair<vector<int>,vector<int>>>>> m;
        for(int i = 0;i < points.size();i++){
            for(int j = i+1;j < points.size();j++){
                vector<int> cur = cal(points[i],points[j]);
                if(m.find(cur[0])==m.end()||m[cur[0]].find(cur[1])==m[cur[0]].end()){
                    m[cur[0]][cur[1]] = vector<pair<vector<int>,vector<int>>>();
                }
                m[cur[0]][cur[1]].push_back(make_pair(points[i],points[j]));
            }
        }
        for(auto x: m){
            for(auto y: x.second){
                if(y.second.size()<2){
                    continue;
                }
                for(int i = 0;i < y.second.size();i++){
                    for(int j = i+1;j < y.second.size();j++){
                        if(is_rec(y.second[i],y.second[j])){
                            ret = min(ret, area(y.second[i],y.second[j]));
                        }
                    }
                }
            }
        }
        if(ret==(double)INT_MAX){
            return 0;
        }
        return ret;
    }
};