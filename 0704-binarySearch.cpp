/*
LeetCode 704. Binary Search
easy
time:	93.57%
space:	72.22%
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();
        while(l<r){
            int mid = (l+r)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]>target){
                r = mid;
            }
            else{
                l = mid+1;
            }
        }
        return -1;
    }
};