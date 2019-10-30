/*
LeetCode 1156. Swap For Longest Repeated Character Substring
medium
time:	12ms
space:	10.2mb
*/
class Solution {
public:
    int maxRepOpt1(string text) {
        unordered_map<char,int> m;
        for(char ch: text){
            m[ch]++;
        }
        int ret = 0;
        vector<pair<char,int>> e;
        int cnt = 1;
        for(int i = 1;i < text.size();++i){
            if(text[i]==text[i-1]){
                ++cnt;
            }
            else{
                e.push_back(make_pair(text[i-1],cnt));
                cnt = 1;
            }
        }
        e.push_back(make_pair(text[text.size()-1],cnt));
        for(int i = 0;i < e.size();++i){
            if(e[i].second==m[e[i].first]){
                ret = max(ret,e[i].second);
            }
            else{
                if(i<e.size()-2&&e[i+1].second==1&&e[i+2].first==e[i].first){
                    if(m[e[i].first]>e[i].second+e[i+2].second)
                        ret = max(ret,e[i].second+e[i+2].second+1);
                    else
                        ret = max(ret,e[i].second+e[i+2].second);
                }
                
                else if(i<e.size()-1||i>0){
                    ret = max(ret,e[i].second+1);
                }
            }
        }
        return ret;
    }
};