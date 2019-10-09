/*
LeetCode 350. Intersection of Two Arrays II
easy
time:	99.37%
space:	55.57%
*/
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size()){
            swap(nums1,nums2);
        }
        unordered_map<int,int> m;
        for(int i = 0;i < nums1.size();i++){
            if(m.find(nums1[i])==m.end()){
                m[nums1[i]] = 0;
            }
            m[nums1[i]]++;
        }
        vector<int> ret;
        for(int i = 0;i < nums2.size();i++){
            if(m.find(nums2[i])!=m.end()&&m[nums2[i]]>0){
                ret.push_back(nums2[i]);
                m[nums2[i]]--;
            }
        }
        return ret;
    }
};