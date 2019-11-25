/*
LeetCode 628. Maximum Product of Three Numbers
easy
time:	68ms
space:	10.7mb
*/
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ret = nums[nums.size()-3]*nums[nums.size()-2]*nums[nums.size()-1];
        if(nums[1]<0&&nums[nums.size()-1]>0){
            ret = max(ret,nums[0]*nums[1]*nums[nums.size()-1]);
        }
        return ret;
    }
};