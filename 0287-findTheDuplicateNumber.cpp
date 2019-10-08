/*
LeetCode 287. Find the Duplicate Number
medium
time:	73.22%
space:	67.5%
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int t = nums[0];
        int r = nums[0];
        while(true){
            t = nums[t];
            r = nums[nums[r]];
            if(r==t){
                break;
            }
        }
        r = nums[0];
        while(r!=t){
            r = nums[r];
            t = nums[t];
        }
        return r;
    }
};