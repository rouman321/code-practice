/*
LeetCode 455. Assign Cookies
easy
time:	49.75%
space:	100%
*/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int l = 0;
        int r = 0;
        int ret = 0;
        while(l<g.size()&&r<s.size()){
            if(s[r]>=g[l]){
                ret++;
                r++;
                l++;
            }
            else{
                r++;
            }
        }
        return ret;
    }
};