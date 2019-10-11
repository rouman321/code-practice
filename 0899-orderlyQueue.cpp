/*
LeetCode 899. Orderly Queue
hard
time:	82.53%
space:	100%
*/
class Solution {
public:
    string orderlyQueue(string S, int K) {
        if(S==""){
            return "";
        }
        string ret = "";
        if(K==1){
            for(int i = 0;i < S.size();i++){
                if(i==0){
                    ret = S;
                }
                else{
                    ret = min(ret,S.substr(i,S.size()-i)+S.substr(0,i));
                }
            }
        }
        else{
            sort(S.begin(),S.end());
            ret = S;
        }
        return ret;
    }
};