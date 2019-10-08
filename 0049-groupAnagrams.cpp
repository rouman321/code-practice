/*
LeetCode 49. Group Anagrams
medium
time:	77.22%
space:	68.66%
*/
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string,int> m;
        for(int i = 0;i < strs.size();i++){
            string key(26,'0');
            for(int j = 0;j < strs[i].size();j++){
                key[strs[i][j]-'a']++;
            }
            if(m.find(key)==m.end()){
                m[key] = ret.size();
                ret.push_back(vector<string>(1,strs[i]));
            }
            else{
                ret[m[key]].push_back(strs[i]);
            }
        }
        return ret;
    }
};