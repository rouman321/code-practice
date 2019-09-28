/*
LeetCode 447. Number of Boomerangs
easy
time:	10.75%
space:	5.88%
*/
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        unordered_map<int,int> m;
        int cnt = 0;
        for(int i = 0;i < points.size();i++){
            m.clear();
            for(int j = 0;j < points.size();j++){
                if(i==j){
                    continue;
                }
                // cout<<cnt<<endl;
                int dist = calc(points[i],points[j]);
                if(m.find(dist)==m.end()){
                    m[dist] = 0;
                }
                m[dist]++;
            }
            for(auto ind: m){
                if(ind.second>=2){
                    cnt += ind.second*(ind.second-1);
                }
            }
        }
        return cnt;
    }
    
    int calc(vector<int> a,vector<int> b){
        return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
    }
};