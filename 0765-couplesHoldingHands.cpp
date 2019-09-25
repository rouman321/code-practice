/*
LeetCode 765. Couples Holding Hands
hard
time	62.27%
space	100%
*/
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        vector<int> m(row.size(),0);
        for(int i = 0;i < row.size();i++){
            m[row[i]] = i;
        }
        int cnt = 0;
        for(int i = 0;i < row.size();i+=2){
            int l = min(row[i],row[i+1]);
            int r = max(row[i],row[i+1]);
            if(l%2!=0||r!=l+1){
                int lm = row[i]%2==0?m[row[i]+1]:m[row[i]-1];
                m[row[i+1]] = lm;
                m[row[lm]] = row[i+1];
                int tmp = row[i+1];
                row[i+1] = row[lm];
                row[lm] = tmp;
                cnt++;
            }
        }
        return cnt;
    }
};