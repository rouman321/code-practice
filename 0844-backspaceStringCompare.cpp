/*
LeetCode 844. Backspace String Compare
easy
time:	4ms
space:	8.3mb
*/
class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int pos = 0;
        int i = 0;
        while(i<S.size()){
            if(S[i]=='#'){
                if(pos>0)
                    --pos;
            }
            else{
                S[pos] = S[i];
                ++pos;
            }
            ++i;
        }
        S = S.substr(0,pos);
        // cout<<S<<endl;
        pos = 0;
        i = 0;
        while(i<T.size()){
            if(T[i]=='#'){
                if(pos>0)
                    --pos;
            }
            else{
                T[pos]=T[i];
                ++pos;
            }
            ++i;
        }
        T = T.substr(0,pos);
        // cout<<T<<endl;
        return S==T;
    }
};