/*
LeetCode 503. Next Greater Element II
medium
time:	26.08%
space:	55.56%
*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len = nums.size();
        vector<int> ret(len,-1);
        stack<int> s;
        for(int i = len*2-1;i >= 0;i--){
            while(!s.empty()&&nums[i%len]>=s.top()){
                s.pop();
            }
            if(!s.empty()){
                ret[i%len] = s.top();
            }
            s.push(nums[i%len]);
        }
        return ret;
    }
};