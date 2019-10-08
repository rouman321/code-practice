/*
LeetCode 997. Find the Town Judge
easy
time:	87.22%
space:	87.5%
*/
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> in(N,0);
        vector<int> out(N,0);
        for(int i = 0;i < trust.size();i++){
            in[trust[i][1]-1]++;
            out[trust[i][0]-1]++;
        }
        int cnt = 0;
        int ret = 0;
        for(int i = 0;i < N;i++){
            if(in[i]==N-1&&out[i]==0){
                cnt++;
                ret = i+1;
            }
        }
        if(cnt==1){
            return ret;
        }
        return -1;
    }
};