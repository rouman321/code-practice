/*
LeetCode 1128. Number of Equivalent Domino Pairs
easy
time:	44ms
space:	21mb
*/
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int,int> m;
        for(int i = 0;i < dominoes.size();++i){
            int a = min(dominoes[i][0],dominoes[i][1]);
            int b = max(dominoes[i][0],dominoes[i][1]);
            if(m.find((a-1)*10+b)==m.end()){
                m[(a-1)*10+b] = 0;
            }
            ++m[(a-1)*10+b];
        }
        int cnt = 0;
        for(auto i :m){
            cnt += i.second*(i.second-1)/2;
        }
        return cnt;
    }
};