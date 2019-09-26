/*
LeetCode 981. Time Based Key-Value Store
medium
time:	41.75%
space:	100%
*/
class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        m.clear();
    }
    
    void set(string key, string value, int timestamp) {
        m[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(m.find(key)==m.end()){
            return "";
        }
        map<int,string,greater<int>>::iterator mi = m[key].lower_bound(timestamp);
        if(mi==m[key].end()){
            return "";
        }
        return mi->second;
    }
    
private:
    unordered_map<string,map<int,string,greater<int>>> m;
};

