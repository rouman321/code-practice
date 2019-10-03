/*
LeetCode 846. Hand of Straights
medium
time:	23.17%
space:	8.33%
*/
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if(hand.size()%W!=0){
            return false;
        }
        unordered_map<int,int> m;
        priority_queue<int,vector<int>,greater<int>> que;
        for(int i = 0;i < hand.size();i++){
            if(m.find(hand[i])==m.end()){
                m[hand[i]] = 0;
            }
            m[hand[i]]++;
            que.push(hand[i]);
        }
        while(!que.empty()){
            int cur = que.top();
            que.pop();
            for(int j = cur;j < cur+W;j++){
                if(m[j]==0){
                    return false;
                }
                m[j]--;
            }
            if(m[cur]==0){
                while(m[cur]==0&&!que.empty()){
                    cur = que.top();
                    que.pop();
                }
                if(m[cur]!=0){
                    que.push(cur);
                }
            }
            else{
                que.push(cur);
            }
        }
        return true;
    }
};