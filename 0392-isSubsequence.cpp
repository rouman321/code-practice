/*
LeetCode 392. Is Subsequence
easy
time:	29.45%
space:	66.67%
*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l = 0;
        int r = 0;
        while(l<s.size()&&r<t.size()){
            if(s[l]==t[r]){
                l++;
            }
            r++;
        }
        return l==s.size();
    }
};