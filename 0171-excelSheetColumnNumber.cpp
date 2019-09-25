/*
LeetCode 171. Excel Sheet Column Number
easy
time	100%
space	65.31%
*/
class Solution {
public:
    int titleToNumber(string s) {
        int pos = 1;
        int ret = 0;
        for(int i = s.size()-1;i>=0;i--){
            if(i!=s.size()-1)
                pos *= 26;
            ret += (s[i]-'A'+1)*pos;
        }
        return ret;
    }
};