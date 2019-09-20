/*
LeetCode 761. Special Binary String
hard
time:   100%
space:  50%
*/

class Solution {
public:
    string makeLargestSpecial(string S) {
        vector<int> presum;
        int sum = 0;
        for(int i = 0;i < S.size();i++){
            sum += S[i]-'0';
            presum.push_back(sum);
        }
        string ret = mount(S,0,S.size(),presum);
        return ret;
    }
    
    string mount(string s, int l, int r, vector<int> presum){
        if(l >= r){
            return "";
        }
        int mid = (l+r)/2;
        int len = mid-l;
        if(presum[mid]-presum[l]==len){
            return s.substr(l,r-l);
        }
        int sum = 0;
        vector<string> cur;
        for(int i = l;i < r;i++){
            sum += s[i]=='1'?1:-1;
            if(sum==0){
                string tmp = "1";
                tmp += mount(s,l+1,i,presum);
                tmp += '0';
                cur.push_back(tmp);
                l = i+1;
            }
        }
        sort(cur.begin(),cur.end(),[](string& a,string& b){return a+b>b+a;});
        string ret = "";
        for(int i = 0;i < cur.size();i++){
            ret += cur[i];
        }
        return ret;
    }
};