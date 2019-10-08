/*
LeetCode 1209. Remove All Adjacent Duplicates in String II
medium
time:	16.31%
space:	100%
*/
class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> m;
        for(int i = 0;i < s.size();i++){
            if(m.empty()){
                m.push(make_pair(s[i],1));
            }
            else{
                if(s[i]==m.top().first){
                    if(m.top().second+1!=k){
                        m.push(make_pair(s[i],m.top().second+1));
                    }
                    else{
                        while(!m.empty()&&m.top().first==s[i]){
                            m.pop();
                        }
                    }
                }
                else{
                    m.push(make_pair(s[i],1));
                }
            }
        }
        string ret = "";
        while(!m.empty()){
            ret = m.top().first+ret;
            m.pop();
        }
        return ret;
    }
};