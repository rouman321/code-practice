/*
LeetCode 752. Open the Lock
medium
time:	64.23%
space:	50%
*/
typedef struct node{
    int cur;
    int step;
}node;

class Solution {
public:
    void find(vector<int>& next, int cur){
        for(int i = 1;i < 10000;i *= 10){
            int tmp = cur;
            if((cur/(i))%10==0){
                tmp = 9*i+cur;
                next.push_back(tmp);
            }
            else{
                tmp = cur-i;
                next.push_back(tmp);
            }
            if((cur/(i))%10==9){
                tmp = cur-9*i;
                next.push_back(tmp);
            }
            else{
                tmp = cur+i;
                next.push_back(tmp);
            }
        }
    }
    
    int openLock(vector<string>& deadends, string target) {
        vector<bool> dead(10000,true);
        for(int i = 0;i < deadends.size();i++){
            if(deadends[i]=="0000"){
                return -1;
            }
            dead[stoi(deadends[i])] = false;
        }
        int t = stoi(target);
        queue<node> q;
        node n;
        n.cur = 0;
        n.step = 0;
        q.push(n);
        while(!q.empty()){
            n = q.front();
            q.pop();
            if(n.cur==t){
                return n.step;
            }
            n.step++;
            vector<int> next;
            find(next,n.cur);
            int tmp = n.cur;
            for(int i = 0;i < next.size();i++){
                if(dead[next[i]]){
                    n.cur = next[i];
                    dead[next[i]] = false;
                    q.push(n);
                }
            }
        }
        return -1;
    }
};