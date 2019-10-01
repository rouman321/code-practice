/*
LeetCode 672. Bulb Switcher II
medium
time:	58.3%
space:	50%
*/
class Solution {
public:
    int flipLights(int n, int m) {
        if (m==0) return 1;
        if (n==1)
            if (m>0)return 2;

        if(n==2)
            if(m==1)return 3;
            else return 4;
        
        if (m==1)return 4;
        if(m==2)return 7;
            return 8;
    }
};