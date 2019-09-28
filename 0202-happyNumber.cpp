/*
LeetCode 202. Happy Number
easy
time:	66.1%
space:	65.38%
*/
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> chart;
        int cur = n;
        while(true){
            cur = cal(cur);
            if(cur==1){
                return true;
            }
            if(chart.find(cur)!=chart.end()){
                break;
            }
            // cout<<cur<<endl;
            chart.insert(cur);
        }
        return false;
    }
    
    int cal(int n){
        if(n == 0){
            return 0;
        }
        int ret = 0;
        while(n>0){
            int tmp = n%10;
            ret += tmp*tmp;
            n /= 10;
        }
        return ret;
    }
};