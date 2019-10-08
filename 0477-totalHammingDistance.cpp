/*
LeetCode 477. Total Hamming Distance
medium
time:	96.35%
space:	60%
*/
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        vector<int> byte(32,0);
        for(int i = 0;i < nums.size();i++){
            int n = nums[i];
            int pos = 0;
            while(n>0){
                byte[pos] += n%2;
                pos++;
                n /= 2;
            }
        }
        int ret = 0;
        for(int i = 0;i < 32;i++){
            ret += (nums.size()-byte[i])*byte[i];
        }
        return ret;
    }
};