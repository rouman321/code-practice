/*
LeetCode 830. Positions of Large Groups
easy
time:	14.06%
space:	100%
*/
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> ret;
        int s = 0;
        int cnt = 1;
        for(int i = 1;i < S.size();i++){
            if(S[i]==S[i-1]){
                cnt++;
            }
            else{
                if(cnt>=3){
                    ret.push_back({s,i-1});
                }
                cnt = 1;
                s = i;
            }
        }
        if(cnt>=3){
            ret.push_back({s,S.size()-1});
        }
        return ret;
    }
};