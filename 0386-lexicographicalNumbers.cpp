/*
LeetCode 386. Lexicographical Numbers
medium
time:	65.64%
space:	54.55%
*/
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ret;
        int i = 1;
        int l = 10;
        stack<int> s;
        stack<int> e;
        while(ret.size()<n){
            ret.push_back(i);
            if(i*10<=n){
                if(i+1!=l){
                    s.push(i+1);
                    e.push(l);
                }
                i *= 10;
                l = i + 10;
            }
            else{
                i++;
                if(i==l||i>n){
                    if(s.empty()){
                        break;
                    }
                    i = s.top();
                    l = e.top();
                    s.pop();
                    e.pop();
                }
            }
        }
        return ret;
    }
};