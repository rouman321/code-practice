/*
LeetCode 598. Range Addition II
easy
time:	89.88%
space:	100%
*/
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int mx = m;
        int my = n;
        for(int i = 0;i < ops.size();i++){
            mx = min(mx,ops[i][0]);
            my = min(my,ops[i][1]);
        }
        return mx*my;
    }
};