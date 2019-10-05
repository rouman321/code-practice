/*
LeetCode 636. Exclusive Time of Functions
medium
time:	96.02%
space:	100%
*/
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ret(n,0);
        stack<int> s;
        for(int i = 0;i < logs.size();i++){
            int j = 0;
            string str = "";
            while(logs[i][j]!=':'){
                str += logs[i][j];
                j++;
            }
            int func = toInt(str);
            j++;
            string status = "";
            while(logs[i][j]!=':'){
                status += logs[i][j];
                j++;
            }
            int time = 0;
            str = "";
            j++;
            while(j<logs[i].size()){
                str += logs[i][j];
                j++;
            }
            time = toInt(str);
            // cout<<str<<" "<<func<<endl;
            if(status == "start"){
                ret[func] -= time;
                if(!s.empty()){
                    ret[s.top()] += time;
                }
                s.push(func);
            }
            else{
                ret[func] += time+1;
                s.pop();
                if(!s.empty()){
                    ret[s.top()] -= time+1;
                }
            }
        }
        return ret;
    }
    
    int toInt(string s){
        int ret = 0;
        for(int i = 0;i < s.size();i++){
            ret *= 10;
            ret += s[i]-'0';
        }
        return ret;
    }
};