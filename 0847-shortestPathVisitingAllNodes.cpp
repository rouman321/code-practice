/*
LeetCode 847. Shortest Path Visiting All Nodes
hard
time:	92.59%
space:	87.5%
*/
class QueNode{
public:
    QueNode(int pos,int c,int s){
        cur = pos;
        check = c;
        step = s;
    }
    int getCur(){
        return cur;
    }
    int getCheck(){
        return check;
    }
    int getStep(){
        return step;
    }
private:
    int cur;
    int check;
    int step;
};

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        queue<QueNode> q;
        int target = 1<<(graph.size());
        vector<vector<bool>> rec(graph.size(),vector<bool>(target,true));
        target -= 1;
        for(int i = 0;i < graph.size();i++){
            q.push(QueNode(i,1<<i,0));
        }
        while(!q.empty()){
            QueNode t = q.front();
            int cur = t.getCur();
            int step = t.getStep();
            int check = t.getCheck();
            // cout<<check<<" "<<target<<endl;
            if(check==target){
                return step;
            }
            q.pop();
            for(int i = 0;i < graph[cur].size();++i){
                int tmp = check;
                tmp |= 1<<graph[cur][i];
                if(rec[graph[cur][i]][tmp]){
                    rec[graph[cur][i]][tmp] = false;
                    q.push(QueNode(graph[cur][i],tmp,step+1));
                }
            }
        }
        return 0;
    }
};

