/*
LeetCode 137. Single Number II
medium
time:	97.41%
space:	100%
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int high = 0;
        int low = 0;
        for (int i=0; i<nums.size(); i++) {
            int high2 = ~high & low & nums[i] | high & ~low & ~nums[i];
            int low2 = ~high & ~low & nums[i] | ~high & low & ~nums[i];
            
            high = high2;
            low = low2;
        }
        return low;
    }
};