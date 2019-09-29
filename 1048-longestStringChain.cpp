/*
LeetCode 1048. Longest String Chain
medium
time:	72.71%
space:	100%
*/
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        vector<int> dp(words.size(),1);
        sort(words.begin(),words.end(),comp);
        unordered_map<string,int> m;
        for(int i = 0;i < words.size();i++){
            m[words[i]] = i;
            if(words.size()>1){
                string l = "";
                string r = words[i].substr(1,words[i].size()-1);
                for(int j = 0;j < words[i].size();j++){
                    string cur = l+r;
                    if(m.find(cur)!=m.end()){
                        dp[i] = max(dp[i],dp[m[cur]]+1);
                    }
                    l += words[i][j];
                    if(r.size()<=1){
                        r = "";
                    }
                    else{
                        r = r.substr(1,r.size()-1);
                    }
                }
            }
        }
        int ret = 0;
        for(int i = 0;i < words.size();i++){
            ret = max(ret,dp[i]);
        }
        return ret;
    }
    bool static comp(string& a,string &b){
        return a.size()<b.size();
    }
};