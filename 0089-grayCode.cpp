/*
LeetCode 89. Gray Code
medium
time:	8ms
space:	8.9mb
*/
class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ret;
        ret.push_back(0);
        unordered_set<int> s;
        s.insert(0);
        int size = 1;
        for(int i = 0;i < n;++i){
            size *= 2;
        }
        int cur = 0;
        while(ret.size()<size){
            for(int i = n-1;i >= 0;--i){
                int tmp = 0;
                if(cur&(1<<i)){
                    tmp = cur-(int)(1<<i);
                }
                else{
                    tmp = cur+(int)(1<<i);
                }
                if(s.find(tmp)==s.end()){
                    ret.push_back(tmp);
                    s.insert(tmp);
                    cur = tmp;
                    break;
                }
            }
        }
        return ret;
    }
};