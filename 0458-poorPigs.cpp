/*
LeetCode 458. Poor Pigs
hard
time:	0ms
space:	8.2ms
*/
class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int attempt = minutesToTest/minutesToDie;
        ++attempt;
        int ret = 0;
        int cur = 1;
        while(cur<buckets){
            cur *= attempt;
            ++ret;
        }
        return ret;
    }
};