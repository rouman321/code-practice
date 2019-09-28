/*
LeetCode 869. Reordered Power of 2
medium
time:	100%
space:	100%
*/
class Solution {
public:
    bool reorderedPowerOf2(int N) {
        string in = "0000000000";
        if(N==0){
            return false;
        }
        in = toString(N);
        int sumin = 0;
        for(int i = 0;i < 10;i++){
            sumin += in[i]-'0';
        }
        // cout<<in<<endl;
        int cur = 1;
        string com = toString(cur);
        int sumcom = 0;
        for(int i = 0;i <10;i++){
            sumcom += com[i]-'0';
        }
        if(N==1){
            return true;
        }
        while(sumcom<=sumin&&sumin<10){
            cur *= 2;
            // cout<<toString(cur)<<endl;
            com = toString(cur);
            if(com==in){
                return true;
            }
            sumcom = 0;
            for(int i = 0;i < 10;i++){
                sumcom += com[i]-'0';
            }
        }
        return false;
    }
    
    string toString(int n){
        if(n==0){
            return "100000000";
        }
        string ret = string(10,'0');
        while(n>0){
            int tmp = n%10;
            ret[tmp]++;
            n /= 10;
        }
        return ret;
    }
};