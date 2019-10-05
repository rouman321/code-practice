/*
LeetCode 1207. Unique Number of Occurrences
easy
time:	73.84%
space:	100%
*/
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> m;
        for(int i = 0;i < arr.size();i++){
            m[arr[i]]++;
        }
        unordered_set<int> s;
        for(auto i :m){
            if(s.find(i.second)!=s.end()){
                return false;
            }
            s.insert(i.second);
        }
        return true;
    }
};