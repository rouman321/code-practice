/*
LeetCode 796. Rotate String
easy
time:	60.01%
space:	93.33%
*/
class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.size()!=B.size()){
            return false;
        }
        if(A.size()==0){
            return true;
        }
        int l = 0;
        while(l<A.size()){
            if(A[l]==B[0]){
                int a = (l+1)%A.size();
                int b = 1;
                while(b<B.size()){
                    if(A[a]!=B[b]){
                        break;
                    }
                    a = (a+1)%A.size();
                    b++;
                }
                if(b==B.size()){
                    return true;
                }
            }
            l++;
        }
        return false;
    }
};