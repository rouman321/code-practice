/*
LeetCode 753. Cracking the Safe
hard
time:	86.03%
space:	100%
*/
class Solution {
public:
    string crackSafe(int n, int k) {
        string ret(n,'0');
        int t = time(n,k);
        int start = 1;
        unordered_set<string> s;
        s.insert(ret);
        while(start<t){
            for(int j = k-1;j >= 0;j--){
                string tmp = ret.substr(start,n-1)+(char)(j+'0');
                if(s.find(tmp)==s.end()){
                    s.insert(tmp);
                    ret += (char)(j+'0');
                    start++;
                    break;
                }
            }
        }
        return ret;
    }
    
    int time(int n, int k){
        int ret = 1;
        for(int i = 0;i < n;i++){
            ret *= k;
        }
        return ret;
    }
};