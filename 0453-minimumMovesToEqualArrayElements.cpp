/*
LeetCode 453. Minimum Moves to Equal Array Elements
easy
time:	68.35%
space:	88.89%
*/
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int cnt = 0;
        int m = nums[0];
        for(int i = 0;i < nums.size();i++){
            m = min(m,nums[i]);
        }
        for(int i = 0;i < nums.size();i++){
            cnt += nums[i]-m;
        }
        return cnt;
    }
};