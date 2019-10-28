/*
LeetCode 11. Container With Most Water
medium
time:	65.54%
space:	100%
*/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size()-1;
        int ret = 0;
        while(l<r){
            ret = max(ret,min(height[l],height[r])*(r-l));
            if(height[l]>height[r]){
                --r;
            }
            else{
                ++l;
            }
        }
        return ret;
    }
};