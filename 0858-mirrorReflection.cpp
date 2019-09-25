/*
LeetCode 858. Mirror Reflection
medium
time	53.23%
space	100%
*/
class Solution {
public:
    int mirrorReflection(int p, int q) {
        int l = gcd(p,q);
        if(q/l%2==0){
            if(p/l%2!=0){
                return 0;
            }
        }
        else{
            if(p/l%2==0){
                return 2;
            }
            return 1;
        }
        return 0;
    }
    
    int gcd(int a, int b){
        int t = 1;
        while(t!=0){
            t = a%b;
            a = b;
            b = t;
        }
        return a;
    }
};