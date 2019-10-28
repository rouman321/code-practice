/*
LeetCode 452. Minimum Number of Arrows to Burst Balloons
medium
time:	72.07%
space:	100%
*/
class Solution {
public:
    bool static cmp(vector<int>& a, vector<int>& b){
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0){
            return 0;
        }
        sort(points.begin(),points.end(),cmp);
        int cnt = 0;
        int x = points[0][1];
        int pos = 0;
        while(pos<points.size()){
            cnt++;
            x = points[pos][1];
            while(pos<points.size()&&x>=points[pos][0]){
                pos++;
            }
        }
        return cnt;
    }
};