/*
LeetCode 697. Degree of an Array
easy
time:	66.92%
space:	100%
*/
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,pair<int,int>> m;
        unordered_map<int,int> cnt;
        for(int i = 0;i < nums.size();i++){
            if(cnt.find(nums[i])==cnt.end()){
                cnt[nums[i]] = 0;
                m[nums[i]] = make_pair(i,i);
            }
            cnt[nums[i]]++;
            m[nums[i]].second = i;
        }
        int d = 0;
        int len = 0;
        for(auto im: m){
            if(cnt[im.first]>d){
                d = cnt[im.first];
                len = im.second.second-im.second.first;
            }
            else if(cnt[im.first]==d&&len>im.second.second-im.second.first){
                len = im.second.second-im.second.first;
            }
        }
        return len+1;
    }
};