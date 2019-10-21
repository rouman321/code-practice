/*
LeetCode 911. Online Election
medium
time:	36.82%
space:	33.33%
*/
struct cmp{
    bool operator()(const int& a, const int& b) const {
        return a>b;
    }
};
class TopVotedCandidate {
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        vote = 0;
        int person = -1;
        for(int i = 0;i < times.size();i++){
            if(m.find(persons[i])==m.end()){
                m[persons[i]] = 0;
            }
            m[persons[i]]++;
            if(m[persons[i]]>=vote){
                // cout<<times[i]<<" "<<persons[i]<<" "<<m[persons[i]]<<endl;
                vote = m[persons[i]];
                if(person!=persons[i]){
                    person = persons[i];
                    check[times[i]] = persons[i];
                }
            }
        }
    }
    
    int q(int t) {
        map<int,int>::iterator cur = check.lower_bound(t);
        // cout<<cur->first<<endl;
        return cur->second;
    }

private:
    unordered_map<int,int> m;
    map<int,int,cmp> check;
    int leader;
    int vote;
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */