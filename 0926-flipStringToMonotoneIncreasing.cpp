/*
LeetCode 926. Flip String to Monotone Increasing
time:   87.04%
*/
class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int min = S.size();
        int cnt = 0;
        for(int i = 0;i < S.size();i++){
            if(S[i]=='1'){
                cnt++;
            }
        }
        min = min-cnt;
        int cost0 = 0;
        int cost1 = min;
        for(int i = 0;i < S.size();i++){
            if(S[i]=='0'){
                cost1--;
            }
            else{
                cost0++;
            }
            if(min>cost1+cost0){
                min = cost0+cost1;
            }
        }
        return min;
    }
};