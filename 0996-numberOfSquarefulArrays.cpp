/*
LeetCode 996. Number of Squareful Arrays
hard
time:	5.14%
space:	100%
*/
typedef struct node{
    int cur;
    unordered_map<int,int> m;
    int passed;
}node;
class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        int limit = 1e9;
        int cur = 0;
        unordered_set<int> squares;
        while(cur*cur<limit){
            squares.insert(cur*cur);
            cur++;
        }
        int target = A.size();
        queue<node> q;
        unordered_map<int,int> m;
        for(int i = 0;i < A.size();i++){
            if(m.find(A[i])==m.end()){
                m[A[i]] = 0;
            }
            m[A[i]]++;
        }
        for(auto i: m){
            node n;
            n.cur = i.first;
            n.passed = 1;
            n.m = m;
            n.m[i.first]--;
            q.push(n);
        }
        int cnt = 0;
        while(!q.empty()){
            node n = q.front();
            // cout<<n.cur<<endl;
            q.pop();
            if(n.passed==target){
                cnt++;
                continue;
            }
            for(auto i: n.m){
                if(i.second>0&&squares.find(n.cur+i.first)!=squares.end()){
                    node next;
                    next.cur = i.first;
                    next.m = n.m;
                    next.m[i.first]--;
                    next.passed = n.passed+1;
                    q.push(next);
                }
            }
        }
        return cnt;
    }
};