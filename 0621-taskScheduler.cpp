/*
LeetCode 621. Task Scheduler
medium
time:	152ms
space:	19mb
*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> num(26,0);
        for(int i = 0;i < tasks.size();++i){
            ++num[tasks[i]-'A'];
        }
        priority_queue<int> q;
        for(int i = 0;i < num.size();++i){
            if(num[i]>0){
                q.push(num[i]);
            }
        }
        int ret = 0;
        while(!q.empty()){
            vector<int> tmp;
            for(int i = 0;i <= n;++i){
                if(!q.empty()){
                    if(q.top()-1!=0){
                        tmp.push_back(q.top()-1);
                    }
                    q.pop();
                    if(q.empty()&&tmp.size()==0){
                        ++ret;
                        break;
                    }
                }
                ++ret;
            }
            for(int i = 0;i < tmp.size();++i){
                q.push(tmp[i]);
            }
        }
        return ret;
    }
};