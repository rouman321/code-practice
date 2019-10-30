/*
LeetCode 833. Find And Replace in String
medium
time:	51.05%
space:	77.78%
*/
class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        map<int,pair<string,string>> m;
        for(int i = 0;i < indexes.size();i++){
            m[indexes[i]] = make_pair(sources[i],targets[i]);
        }
        int cur = 0;
        string ret = "";
        for(auto i: m){
            if(cur!=i.first){
                ret += S.substr(cur,i.first-cur);
            }
            int len = i.second.first.size();
            if(S.substr(i.first,len)==i.second.first){
                ret += i.second.second;
                cur = i.first+len;
            }
            else{
                cur = i.first;
            }
        }
        if(cur!=S.size()){
            ret += S.substr(cur,S.size()-cur);
        }
        return ret;
    }
};