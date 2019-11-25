/*
LeetCode 541. Reverse String II
easy
time:	8ms
space:	9.5mb
*/
class Solution {
public:
    string reverseStr(string s, int k) {
        int pos = 0;
        int n = s.size();
        while(pos<s.size()){
            int end = min(n,pos+k);
            for(int i = pos;i < (pos+end)/2;++i){
                swap(s[i],s[end-i-1+pos]);
            }
            pos = end+k;
        }
        return s;
    }
};