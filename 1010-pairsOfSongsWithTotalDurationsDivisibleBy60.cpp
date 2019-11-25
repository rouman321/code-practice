/*
LeetCode 1010. Pairs of Songs With Total Durations Divisible by 60
easy
time:	36ms
space:	11.7mb
*/
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> mod(60,0);
        for(int i = 0;i < time.size();++i){
            ++mod[time[i]%60];
        }
        int ret = 0;
        int pos = 1;
        while(pos!=30){
            ret += mod[pos]*mod[60-pos];
            ++pos;
        }
        ret += mod[0]*(mod[0]-1)/2+mod[30]*(mod[30]-1)/2;
        return ret;
    }
};