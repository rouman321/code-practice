/*
LeetCode 851. Loud and Rich
medium
time:	72.7%
space:	100%
*/
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        vector<vector<int>> rich(quiet.size(),vector<int>());
        vector<int> degree(quiet.size(),0);
        for(int i = 0;i < richer.size();i++){
            rich[richer[i][0]].push_back(richer[i][1]);
            degree[richer[i][1]]++;
        }
        queue<int> que;
        vector<int> ret(quiet.size(),-1);
        for(int i = 0;i < ret.size();i++){
            ret[i] = i;
            if(degree[i]==0){
                que.push(i);
            }
        }
        while(!que.empty()){
            int cur = que.front();
            que.pop();
            for(int i = 0;i < rich[cur].size();i++){
                degree[rich[cur][i]]--;
                if(degree[rich[cur][i]]==0){
                    que.push(rich[cur][i]);
                }
                if(quiet[ret[rich[cur][i]]]>quiet[ret[cur]]){
                    ret[rich[cur][i]] = ret[cur];
                }
            }
        }
        return ret;
    }
};