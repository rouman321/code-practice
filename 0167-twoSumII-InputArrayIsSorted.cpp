/*
LeetCode 167. Two Sum II - Input array is sorted
easy
time:	96.98%
space:	62.74%
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size()-1;
        vector<int> ret;
        while(l<r){
            int sum = numbers[l]+numbers[r];
            if(sum==target){
                ret.push_back(l+1);
                ret.push_back(r+1);
                return ret;
            }
            if(sum>target){
                --r;
            }
            else{
                ++l;
            }
        }
        return ret;
    }
};