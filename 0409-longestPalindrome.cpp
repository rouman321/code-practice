/*
LeetCode 409. Longest Palindrome
easy
time:	83.11%
space:	93.33%
*/
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> m(52,0);
        for(int i = 0;i < s.size();i++){
            if(s[i]>='a'&&s[i]<='z')
                m[s[i]-'a']++;
            else
                m[s[i]-'A'+26]++;
        }
        int ret = 0;
        for(int i = 0;i < 52;i++){
            ret += m[i]-m[i]%2;
        }
        if(ret < s.size()){
            return ret+1;
        }
        return ret;
    }
};