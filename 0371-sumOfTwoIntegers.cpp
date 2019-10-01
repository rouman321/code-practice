/*
LeetCode 371. Sum of Two Integers
easy
time:	100%
space:	100%
*/
class Solution {
public:
    int getSum(int a, int b) {
        
        while(b != 0)
        {
            unsigned int carry = a&b;
            a = a^b;
            b = carry<<1;
        }
        
        return a;
    }
};