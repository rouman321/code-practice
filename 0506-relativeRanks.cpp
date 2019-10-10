/*
LeetCode 506. Relative Ranks
easy
time:	55.75%
space:	33.33%
*/
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<int> rank(nums);
        sort(rank.begin(),rank.end());
        unordered_map<int,string> m;
        for(int i = rank.size()-1;i >= 0;i--){
            m[rank[i]] = to_string(rank.size()-i);
        }
        vector<string> ret;
        for(int i = 0;i < nums.size();i++){
            if(stoi(m[nums[i]])>3){
                ret.push_back(m[nums[i]]);
            }
            else if(m[nums[i]]=="1"){
                ret.push_back("Gold Medal");
            }
            else if(m[nums[i]]=="2"){
                ret.push_back("Silver Medal");
            }
            else{
                ret.push_back("Bronze Medal");
            }
        }
        return ret;
    }
};