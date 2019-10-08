/*
LeetCode 539. Minimum Time Difference
medium
time:	31.99%
space:	100%
*/
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(),timePoints.end());
        int diff = -1;
        for(int i = 1;i< timePoints.size();i++){
            int cur = toMinutes(timePoints[i])-toMinutes(timePoints[i-1]);
            if(cur*2>1440){
                cur = 1440-cur;
            }
            if(diff==-1){
                diff = cur;
            }
            else{
                diff = min(diff,cur);
            }
            // cout<<cur<<endl;
        }
        int last = toMinutes(timePoints[timePoints.size()-1])-toMinutes(timePoints[0]);
        if(last*2>1440){
            last = 1440-last;
        }
        diff = min(diff,last);
        return diff;
    }
    
    int toInt(string s){
        int ret = 0;
        for(int i = 0;i < s.size();i++){
            ret *= 10;
            ret += s[i]-'0';
        }
        return ret;
    }
    
    int toMinutes(string s){
        string time = "";
        int i = 0;
        while(s[i]!=':'){
            time += s[i];
            i++;
        }
        i++;
        int ret = toInt(time)*60;
        time = "";
        while(i<s.size()){
            time += s[i];
            i++;
        }
        ret += toInt(time);
        return ret;
    }
};