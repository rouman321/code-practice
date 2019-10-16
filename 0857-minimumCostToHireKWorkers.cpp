/*
LeetCode 857. Minimum Cost to Hire K Workers
hard
time:	30.33%
space:	100%
*/
class Solution {
public:
    bool static cmp(pair<int,int> a, pair<int,int> b){
        return (double)a.first/a.second<(double)b.first/b.second;
    }
    
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        priority_queue<int> que;
        int s = 0;
        vector<pair<int,int>> w;
        for(int i = 0;i < quality.size();i++){
            w.push_back(make_pair(wage[i],quality[i]));
        }
        sort(w.begin(),w.end(),cmp);
        double ret = 1e9;
        for(int i = 0;i < w.size();i++){
            que.push(w[i].second);
            s += w[i].second;
            if(que.size()>K){
                s -= que.top();
                que.pop();
            }
            if(que.size()==K){
                ret = min(ret,(double)w[i].first/w[i].second*s);
            }
        }
        return ret;
    }
};