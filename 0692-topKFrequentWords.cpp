/*
LeetCode 692. Top K Frequent Words
medium
time:	44.28%
space:	94.44%
*/
class cmp{
public:
    bool operator()(pair<string,int>&a, pair<string,int>& b){
        if(a.second!=b.second){
            return a.second>b.second;
        }
        return a.first<b.first;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<string,int>,vector<pair<string,int>>,cmp> q;
        unordered_map<string,int> m;
        for(int i = 0;i < words.size();i++){
            if(m.find(words[i])==m.end()){
                m[words[i]] = 0;
            }
            m[words[i]]++;
        }
        for(auto i: m){
            if(q.size()<k){
                q.push(make_pair(i.first,i.second));
            }
            else{
                if(i.second>q.top().second||(i.second==q.top().second&&i.first<q.top().first)){
                    q.pop();
                    q.push(make_pair(i.first,i.second));
                }
            }
        }
        vector<string> ret;
        while(!q.empty()){
            ret.insert(ret.begin(),q.top().first);
            q.pop();
        }
        return ret;
    }
};