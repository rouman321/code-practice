/*
LeetCode 394. Decode String
medium
*/
/*
time:	4ms
space:	8.9mb
*/
class Solution {
public:
    string decodeString(string s) {
        // cout<<s<<endl;
        string ret = "";
        int i = 0;
        string num = "";
        while(i<s.size()){
            if(s[i]<='9'&&s[i]>='0'){
                while(s[i]!='['){
                    num += s[i];
                    ++i;
                }
                string next = "";
                ++i;
                int cnt = 0;
                while(s[i]!=']'||cnt!=0){
                    if(s[i]=='['){
                        ++cnt;
                    }
                    if(s[i]==']'){
                        --cnt;
                    }
                    next += s[i];
                    ++i;
                }
                string substr = decodeString(next);
                for(int j = 0;j < stoi(num);++j){
                    ret += substr;
                }
                num = "";
            }
            else{
                ret += s[i];
            }
            ++i;
        }
        return ret;
    }
};
/*
non recursive ver.
time:	4ms
space:	9.4mb
*/
class Solution {
public:
    string decodeString(string s) {
        string ret = "";
        int i = 0;
        string num = "";
        stack<string> m;
        while(i<s.size()){
            if(s[i]!=']'){
                string tmp = "";
                tmp += s[i];
                m.push(tmp);
            }
            else{
                string rep = "";
                while(m.top()!="["){
                    rep = m.top()+rep;
                    m.pop();
                }
                m.pop();
                num = "";
                while(!m.empty()&&m.top()<="9"&&m.top()>="0"){
                    num = m.top()+num;
                    m.pop();
                }
                for(int j = 0;j < stoi(num);++j){
                    m.push(rep);
                }
            }
            ++i;
        }
        while(!m.empty()){
            ret = m.top()+ret;
            m.pop();
        }
        return ret;
    }
};