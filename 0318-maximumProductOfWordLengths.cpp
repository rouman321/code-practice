/*
LeetCode 318. Maximum Product of Word Lengths
medium
time:	37.98%
space:	93.33%
*/
class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> mark(words.size(),0);
        for(int i = 0;i < words.size();i++){
            for(int j = 0;j < words[i].size();j++){
                int cur = 1<<(words[i][j]-'a');
                mark[i] += mark[i]&cur?0:cur;
            }
        }
        int m = 0;
        for(int i = 0;i < words.size();i++){
            for(int j = i+1;j < words.size();j++){
                if(mark[i]&mark[j]){
                    continue;
                }
                int len = words[i].size()*words[j].size();
                m = max(m,len);
            }
        }
        return m;
    }
};