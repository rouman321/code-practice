/*
LeetCode 611. Valid Triangle Number
medium
time:	12ms
space:	8.6mb
*/
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt = 0;
        for(int i = 0;i < nums.size();++i){
            int k = i+2;
            for(int j = i+1;j < nums.size();++j){
                if(j==k){
                    ++k;
                }
                while(k<nums.size()&&nums[k]<nums[i]+nums[j]){
                    ++k;
                }
                cnt += k-j-1;
            }
        }
        return cnt;
    }
};