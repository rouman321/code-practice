/*
LeetCode 481. Magical String
medium
time:	8ms
space:	9.9mb
*/
class Solution {
public:
    int magicalString(int n) {
        string s = "122";
        char ch = '1';
        if(n==0){
            return 0;
        }
        if(n<=3){
            return 1;
        }
        int cnt = 1;
        int pos = 2;
        while(s.size()<n){
            for(int i = 0;i < s[pos]-'0';++i){
                s += ch;
                if(ch=='1'){
                    ++cnt;
                }
                if(s.size()==n){
                    break;
                }
            }
            ch = ch=='1'?'2':'1';
            ++pos;
        }
        return cnt;
    }
};