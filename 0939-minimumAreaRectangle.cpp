/*
LeetCode 939. Minimum Area Rectangle
medium
time:	7.82%
space:	75%
*/
class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int,unordered_set<int>> m;
        for(int i = 0;i < points.size();i++){
            m[points[i][0]].insert(points[i][1]);
        }
        int ret = 0;
        for(int i = 0;i < points.size();i++){
            for(int j = 0;j < points.size();j++){
                if(points[i][0]!=points[j][0]&&points[i][1]!=points[j][1]){
                    if(m[points[i][0]].find(points[j][1])!=m[points[i][0]].end()&&m[points[j][0]].find(points[i][1])!=m[points[j][0]].end()){
                        if(ret==0){
                            ret = abs(points[i][0]-points[j][0])*abs(points[i][1]-points[j][1]);
                        }
                        else{
                            ret = min(ret,abs(points[i][0]-points[j][0])*abs(points[i][1]-points[j][1]));
                        }
                    }
                }
            }
        }
        return ret;
    }
};